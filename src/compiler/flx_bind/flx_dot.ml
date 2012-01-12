open Flx_util
open Flx_list
open Flx_ast
open Flx_types
open Flx_btype
open Flx_bparameter
open Flx_bexpr
open Flx_bbdcl
open Flx_print
open Flx_exceptions
open Flx_set
open Flx_mtypes2
open Flx_typing
open Flx_typing2
open Flx_unify
open Flx_beta
open Flx_generic
open Flx_overload
open Flx_tpat

type lookup_state_t = {
  counter : bid_t ref;
  print_flag: bool;
  ticache : (bid_t, Flx_btype.t) Hashtbl.t;
  varmap: Flx_mtypes2.typevarmap_t; 
    (* used by unification to fix the return types of functions
     * MUST be a reference to the global one because that's used
     * in the front and back ends extensively..
     *)
  sym_table: Flx_sym_table.t;
  env_cache: (Flx_types.bid_t, Flx_mtypes2.env_t) Hashtbl.t;
}


let hfind msg h k =
  try Flx_sym_table.find h k
  with Not_found ->
    print_endline ("flx_lookup Flx_sym_table.find failed " ^ msg);
    raise Not_found

let get_data table index =
  try Flx_sym_table.find table index
  with Not_found ->
    failwith ("[Flx_lookup.get_data] No definition of <" ^
      string_of_bid index ^ ">")

let rsground= {
  constraint_overload_trail = [];
  idx_fixlist = [];
  type_alias_fixlist = [];
  as_fixlist = [];
  expr_fixlist = [];
  depth = 0;
  open_excludes = []
}

(*
  Order of sugars for operator dot.

  1. If the lhs and rhs are functions and the codomain of the lhs agrees with
      the domain of the rhs, this is a reverse composition, eg:

      1 . (str . trim) --> compose(trim, str) 1
 
  2. If the lhs is a struct, cstruct, or record AND the rhs is a simple name
      AND the name is a component, it's the component

  3. Try get method (now, for any type not just struct!)

  4. Try reverse application

  5. Deref once, try for field name. If found, result is POINTER to component.

  PROPERTIES
  ----------

  Commutativity of reverse composition and reverse application, eg:

  1 . str . trim == (1 . str) . trim == 1 . (str . trim)

  This property is VITAL for comprehension: the dot operator is syntactically
  associative. SPECIAL NOTE: COUNTEREXAMPLE: for any non-polymorphic function
  it is impossible to confuse composition and application. But for polymorphic
  functions it's possible! Therefore the order MATTERS.
  

*)

exception Not_field

let handle_field_name state bsym_table build_env env rs be bt koenig_lookup cal_apply bind_type' mkenv 
  sr e e2 name ts i ts' isptr
=
  let rt t = beta_reduce state.counter bsym_table sr t in
  let (_,t) as te = be e in
  let ttt =rt t in
  match hfind "lookup" state.sym_table i with

  (* STRUCT *)
  | { Flx_sym.id=id; vs=vs; sr=sra; symdef=SYMDEF_struct ls }
  | { Flx_sym.id=id; vs=vs; sr=sra; symdef=SYMDEF_cstruct (ls,_) } ->
    let _,vs,_ = find_split_vs state.sym_table bsym_table i in
    let cidx,ct =
      let rec scan i = function
      | [] -> raise Not_field
      | (vn,vat)::_ when vn = name -> i,vat
      | _:: t -> scan (i+1) t
      in scan 0 ls
    in
    let ct =
      let bvs = List.map
        (fun (n,i,_) -> n, btyp_type_var (i, btyp_type 0))
        (vs)
      in
      let env' = build_env state bsym_table (Some i) in
      bind_type' state bsym_table env' rsground sr ct bvs mkenv
    in
    let vs' = List.map (fun (s,i,tp) -> s,i) vs in
    let ct = tsubst vs' ts' ct in
    let ct = if isptr then btyp_pointer ct else ct in
    bexpr_get_n ct (cidx,te)
  | _ ->  raise Not_field

let handle_dot state bsym_table build_env env rs be bt koenig_lookup cal_apply bind_type' sr e e2 =
  let mkenv i = build_env state bsym_table (Some i) in
  let rt t = beta_reduce state.counter bsym_table sr t in

  let (_,tt) as te = be e in (* polymorphic! *)
  let ttt = rt tt in
  begin match e2 with

  (* RHS IS A SIMPLE NAME *)
  | EXPR_name (_,name,ts) ->
    begin match ttt with

    (* LHS HAS POINTER TYPE *)
    | BTYP_pointer (BTYP_inst (i,ts')) ->
      begin 
      try
        handle_field_name state bsym_table build_env env rs be bt 
          koenig_lookup cal_apply bind_type' mkenv sr e e2 name ts i ts' true
      with Not_field ->
      try be (EXPR_apply (sr,(e2,e)))
      with exn ->
        clierr sr
        (
          "[bind_expression] operator dot: Field " ^ name ^
          " is not a member of structure type " ^
           sbt bsym_table ttt ^
           "\n and trying reverse application of " ^ name ^
           " as a function also failed"
        )
      end


    | BTYP_pointer (BTYP_record ("",es) ) ->
      let rcmp (s1,_) (s2,_) = compare s1 s2 in
      let es = List.sort rcmp es in
      let field_name = name in
      begin match list_index (List.map fst es) field_name with
      | Some n -> bexpr_get_n (btyp_pointer (List.assoc field_name es)) (n,te)
      | None ->
      try be (EXPR_apply (sr,(e2,e)))
      with exn ->
      clierr sr
        (
          "[bind_expression] operator dot: Field " ^ name ^
          " is not a member of derefed pointer to record type " ^
           sbt bsym_table ttt ^
           "\n and trying reverse application of " ^ name ^
           " as a function also failed"
        )
      end

    (* LHS HAS A NOMINAL TYPE *)
    | BTYP_inst (i,ts') ->
      begin 
      try
        handle_field_name state bsym_table build_env env rs be bt 
          koenig_lookup cal_apply bind_type' mkenv sr e e2 name ts i ts' false
      with Not_field ->
      try be (EXPR_apply (sr,(e2,e)))
      with exn ->
        clierr sr
        (
          "[bind_expression] operator dot: Field " ^ name ^
          " is not a member of structure type " ^
           sbt bsym_table ttt ^
           "\n and trying reverse application of " ^ name ^
           " as a function also failed"
        )
      end

    (* LHS HAS A RECORD TYPE *)
    | BTYP_record ("",es) ->
      let rcmp (s1,_) (s2,_) = compare s1 s2 in
      let es = List.sort rcmp es in
      let field_name = name in
      begin match list_index (List.map fst es) field_name with
      | Some n -> bexpr_get_n (List.assoc field_name es) (n,te)
      | None ->
        try be (EXPR_apply (sr,(e2,e)))
        with exn ->
        clierr sr
        (
          "[bind_expression] operator dot: Field " ^ name ^
          " is not a member of record type " ^
           sbt bsym_table ttt ^
           "\n and trying reverse application of " ^ name ^
           " as a function also failed"
        )
      end

    (* LHS FUNCTION TYPE *)
    | BTYP_function (d,c) ->
      (* print_endline ("AST_dot: LHS function, RHS name= " ^ name ); *)
      let bound = begin try be (EXPR_apply (sr,(e2,e)))
      with exn ->
      (* print_endline "Reverse application failed, checking for composition"; *)
      try 
        let r,rt = be e2 in
        match rt with
        | BTYP_function (a,b) ->
          (* print_endline "RHS is a function"; *)
          (* NOTE: this is WRONG: it only works for non-polymorphic types. Clearly
             f[t]: list[t] -> list[t]
             g[u]: list[u] -> list[u]
             can be composed, so equality of terms is the wrong idea: we need 
             equality "modulo" names of the type variables. 
          *)
          if c = a then (
            (* print_endline "Composed!";  *)
            bexpr_compose (btyp_function (d,b)) (te,(r,rt))
          )
          else
           clierr sr (
             "AST_dot " ^ string_of_expr e ^ " . " ^ string_of_expr e2^
             "codomain of LHS function should match domain of RHS function"
           )

        | _ -> 
          clierr sr (
          "AST_dot, LHS function, RHS arg "^ string_of_expr e2^
          " is simple name, should have been a function but got " ^
          Printexc.to_string exn
          )
      with exn2 ->
        clierr sr (
        "AST_dot, LHS function, RHS arg "^ string_of_expr e2^
        " is simple name, and attempt to bind it failed with " ^
        Printexc.to_string exn2
        )
      end
      in
      (* print_endline "AST_dot, RHS simple name, is done"; *)
      bound

    (* LHS TUPLE TYPE *)
    | BTYP_tuple _ ->
      begin try be (EXPR_apply (sr,(e2,e)))
      with exn ->
      clierr sr (
      "AST_dot, arg "^ string_of_expr e2^
      " is simple name, and attempt to apply it failed with " ^
      Printexc.to_string exn
      )
      end

    (* LHS OTHER ALGEBRAIC TYPE *)
    | _ ->
      begin try be (EXPR_apply (sr,(e2,e)))
      with exn ->
      clierr sr (
      "AST_dot, arg "^ string_of_expr e2^
      " is simple name, and attempt to apply it failed with " ^
      Printexc.to_string exn
      )
      end
    end

  (* RHS NOT A SIMPLE NAME: reverse application OR composition?? *)
  | _ ->
    begin try be (EXPR_apply (sr,(e2,e)))
    with exn ->
    (* print_endline "Reverse application failed, checking for composition"; *)
    match ttt with
    | BTYP_function (d,c) -> (* LHS *)
      (* print_endline ("AST_dot: LHS function, RHS function expr= " ^ * string_of_expr e2); *)
      begin try 
        let r,rt = be e2 in
        match rt with
        | BTYP_function (a,b) -> (* RHS *)
          (* print_endline "RHS is a function"; *)
          if c = a then (
            (* print_endline "Composed!";  *)
            bexpr_compose (btyp_function (d,b)) (te,(r,rt))
          )
          else
           clierr sr (
             "AST_dot " ^ string_of_expr e ^ " . " ^ string_of_expr e2^
             "codomain of LHS function should match domain of RHS function"
           )

        | _ -> 
          clierr sr (
          "AST_dot, LHS function, RHS arg "^ string_of_expr e2^
          " is expr, could have been a function but got " ^
          sbt bsym_table rt ^
          " and reverse application also failed."
          )
      with exn2 ->
        clierr sr (
        "AST_dot, LHS function, RHS arg "^ string_of_expr e2^
        " is expression, and attempt to bind it failed with " ^
        Printexc.to_string exn2
        )
      end

    | _ -> (* LHS not function *)
    clierr sr (
      "AST_dot, arg "^ string_of_expr e2^
      " is not simple name, and attempt to apply it failed with " ^
      Printexc.to_string exn
      )
    end
end

