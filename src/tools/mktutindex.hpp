#ifndef _FLX_GUARD_mktutindex
#define _FLX_GUARD_mktutindex
//Input file: src/tools/mktutindex.flx
//Generated by Felix Version 1.1.7dev
//Timestamp: 2011/12/11 13:1:36 UTC
//Timestamp: 2011/12/11 23:1:36 (local)

//FELIX RUNTIME
#include "flx_rtl.hpp"
#include "flx_gc.hpp"
#ifndef FLX_NO_INCLUDES
#include "mktutindex.includes"
#endif


//-----------------------------------------
//USER HEADERS
#include "flx_rtl_config.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

//-----------------------------------------
//FELIX SYSTEM
namespace flxusr { namespace mktutindex {
struct thread_frame_t;

//-----------------------------------------
//NAME THE TYPES

//PRIMITIVE 5142 INSTANCE 54007: string
typedef ::std::basic_string<char> _a5142t_54007;
typedef int _us2;

//TYPE 54009: string^2
struct _at54009;

//PRIMITIVE 2522 INSTANCE 54010: int
//typedef int int;

//TYPE 54011: int^2
struct _at54011;

//PRIMITIVE 7480 INSTANCE 54012: RE2
typedef ::re2::RE2* _a7480t_54012;

//PRIMITIVE 7479 INSTANCE 54013: RE2_
typedef ::re2::RE2 _a7479t_54013;

//TYPE 54014: bool^2
struct _at54014;

//PRIMITIVE 2515 INSTANCE 54016: address
typedef void * _a2515t_54016;

//PRIMITIVE 10907 INSTANCE 54017: dirent_t
typedef struct dirent* _a10907t_54017;

//PRIMITIVE 10908 INSTANCE 54018: DIR_t
typedef DIR* _a10908t_54018;

//TYPE 54019: string * &DIR_t
struct _tt54019;

//PRIMITIVE 4318 INSTANCE 54020: ostream
typedef ::std::ostream* _a4318t_54020;

//TYPE 54021: ostream * string
struct _tt54021;

//TYPE 54023: DIR_t * dirent_t * &dirent_t * &int
struct _tt54023;

//TYPE 54024: list[string] * string
struct _tt54024;

//TYPE 54025: string * list[string]
struct _tt54025;

//TYPE 54026: string -> void
struct _pt54026;

//PRIMITIVE 4292 INSTANCE 54027: output_text_file
typedef FILE* _a4292t_54027;

//TYPE 54028: output_text_file * string
struct _tt54028;

//PRIMITIVE 4291 INSTANCE 54029: input_text_file
typedef FILE* _a4291t_54029;

//PRIMITIVE 2517 INSTANCE 54030: char
//typedef char char;

//TYPE 54031: char^2
struct _at54031;

//TYPE 54032: string * int
struct _tt54032;

//PRIMITIVE 10768 INSTANCE 54055: stat_t
typedef struct stat _a10768t_54055;

//TYPE 54056: string * &stat_t * &int
struct _tt54056;

//PRIMITIVE 10797 INSTANCE 54057: mode_t
//typedef mode_t mode_t;

//TYPE 54058: mode_t^2
struct _at54058;

//PRIMITIVE 10684 INSTANCE 54060: errno_t
typedef int _a10684t_54060;

//TYPE 54061: errno_t^2
struct _at54061;

//PRIMITIVE 7482 INSTANCE 54062: StringPiece
typedef ::re2::StringPiece _a7482t_54062;

//PRIMITIVE 7543 INSTANCE 54063: Anchor
typedef ::re2::RE2::Anchor _a7543t_54063;

//TYPE 54064: RE2 * StringPiece * int * Anchor * &StringPiece * int
struct _tt54064;

//TYPE 54065: &list[string]^2
struct _at54065;

//TYPE 54066: &list[string] * list[string]
struct _tt54066;


//-----------------------------------------
//DEFINE THE TYPES

//TYPE 54009: string^2
struct _at54009 {
  static size_t const len = 2;
  typedef _a5142t_54007 element_type;
  _a5142t_54007 data[2];
  _at54009() {}
  _at54009(_a5142t_54007 a0, _a5142t_54007 a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54011: int^2
struct _at54011 {
  static size_t const len = 2;
  typedef int element_type;
  int data[2];
  _at54011() {}
  _at54011(int a0, int a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54014: bool^2
struct _at54014 {
  static size_t const len = 2;
  typedef _us2 element_type;
  _us2 data[2];
  _at54014() {}
  _at54014(_us2 a0, _us2 a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54019: string * &DIR_t
struct _tt54019 {
  _a5142t_54007 mem_0;
  _a10908t_54018* mem_1;
  _tt54019(){}
  _tt54019(_a5142t_54007 a0, _a10908t_54018* a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54021: ostream * string
struct _tt54021 {
  _a4318t_54020 mem_0;
  _a5142t_54007 mem_1;
  _tt54021(){}
  _tt54021(_a4318t_54020 a0, _a5142t_54007 a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54023: DIR_t * dirent_t * &dirent_t * &int
struct _tt54023 {
  _a10908t_54018 mem_0;
  _a10907t_54017 mem_1;
  _a10907t_54017* mem_2;
  int* mem_3;
  _tt54023(){}
  _tt54023(_a10908t_54018 a0, _a10907t_54017 a1, _a10907t_54017* a2, int* a3):
    mem_0(a0), mem_1(a1), mem_2(a2), mem_3(a3){}
};

//TYPE 54024: list[string] * string
struct _tt54024 {
  void* mem_0;
  _a5142t_54007 mem_1;
  _tt54024(){}
  _tt54024(void* a0, _a5142t_54007 a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54025: string * list[string]
struct _tt54025 {
  _a5142t_54007 mem_0;
  void* mem_1;
  _tt54025(){}
  _tt54025(_a5142t_54007 a0, void* a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54026: string -> void
struct _pt54026: ::flx::rtl::con_t {
  typedef void rettype;
  typedef _a5142t_54007 argtype;
  virtual ::flx::rtl::con_t *call(::flx::rtl::con_t *, _a5142t_54007 const &)=0;
  virtual _pt54026 *clone()=0;
  virtual ::flx::rtl::con_t *resume()=0;
};

//TYPE 54028: output_text_file * string
struct _tt54028 {
  _a4292t_54027 mem_0;
  _a5142t_54007 mem_1;
  _tt54028(){}
  _tt54028(_a4292t_54027 a0, _a5142t_54007 a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54031: char^2
struct _at54031 {
  static size_t const len = 2;
  typedef char element_type;
  char data[2];
  _at54031() {}
  _at54031(char a0, char a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54032: string * int
struct _tt54032 {
  _a5142t_54007 mem_0;
  int mem_1;
  _tt54032(){}
  _tt54032(_a5142t_54007 a0, int a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54056: string * &stat_t * &int
struct _tt54056 {
  _a5142t_54007 mem_0;
  _a10768t_54055* mem_1;
  int* mem_2;
  _tt54056(){}
  _tt54056(_a5142t_54007 a0, _a10768t_54055* a1, int* a2):
    mem_0(a0), mem_1(a1), mem_2(a2){}
};

//TYPE 54058: mode_t^2
struct _at54058 {
  static size_t const len = 2;
  typedef mode_t element_type;
  mode_t data[2];
  _at54058() {}
  _at54058(mode_t a0, mode_t a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54061: errno_t^2
struct _at54061 {
  static size_t const len = 2;
  typedef _a10684t_54060 element_type;
  _a10684t_54060 data[2];
  _at54061() {}
  _at54061(_a10684t_54060 a0, _a10684t_54060 a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54064: RE2 * StringPiece * int * Anchor * &StringPiece * int
struct _tt54064 {
  _a7480t_54012 mem_0;
  _a7482t_54062 mem_1;
  int mem_2;
  _a7543t_54063 mem_3;
  _a7482t_54062* mem_4;
  int mem_5;
  _tt54064(){}
  _tt54064(_a7480t_54012 a0, _a7482t_54062 a1, int a2, _a7543t_54063 a3, _a7482t_54062* a4, int a5):
    mem_0(a0), mem_1(a1), mem_2(a2), mem_3(a3), mem_4(a4), mem_5(a5){}
};

//TYPE 54065: &list[string]^2
struct _at54065 {
  static size_t const len = 2;
  typedef void** element_type;
  void** data[2];
  _at54065() {}
  _at54065(void** a0, void** a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54066: &list[string] * list[string]
struct _tt54066 {
  void** mem_0;
  void* mem_1;
  _tt54066(){}
  _tt54066(void** a0, void* a1):
    mem_0(a0), mem_1(a1){}
};


//-----------------------------------------
//DEFINE FUNCTION CLASS NAMES
struct _lam_10440;
struct _init_;
struct rfi;
struct _i21688_f21688__lam_10617__apos_2;
struct _i21722_f21722__lam_10617__apos_2;
struct println;
struct _i43866_f43866__lam_10617__apos_2;


//-----------------------------------------
//DEFINE FUNCTION CLASSES

//------------------------------
//FUNCTION <10969>: _lam_10440
struct _lam_10440: _pt54026 {
  FLX_FMEM_DECL

  int j;
  _us2 found;
  int i;
  int _i20603_v20603_j;
  _us2 _i20602_v20602_found;
  int _i20601_v20601_i;
  _a5142t_54007 _urv19213;
  _a5142t_54007 _urv19884;
  _a5142t_54007 hline;
  _a4291t_54029 f;
  _a5142t_54007 x;
  _lam_10440(FLX_FPAR_DECL_ONLY);
  _lam_10440* clone();
  ::flx::rtl::con_t *call(::flx::rtl::con_t*,_a5142t_54007 const &);
  ::flx::rtl::con_t *resume();
};

//------------------------------
//FUNCTION <11494>: _init_
struct _init_: ::flx::rtl::con_t {
  FLX_FMEM_DECL

  void* t;
  void* _i43911_v43911_iter__apos_2_mv_992;
  _pt54026* _f_uncurry;
  void* _i43909_v43909_x;
  void* _i43902_v43902_t;
  void* _i43901_v43901_iter__apos_2_mv_992;
  _pt54026* _i43900_v43900__f_uncurry;
  void* _i43899_v43899_x;
  void* _i22898_v22898_t;
  void* _i22897_v22897_iter__apos_2_mv_992;
  _pt54026* _i22896_v22896__f_uncurry;
  int _i22270_v22270_j;
  _us2 _i22269_v22269_found;
  int _i22268_v22268_i;
  int _i22267_v22267_j;
  _us2 _i22266_v22266_found;
  int _i22265_v22265_i;
  _a5142t_54007 _i22264_v22264__urv19213;
  _a5142t_54007 _i22263_v22263__urv19884;
  _a5142t_54007 _i22262_v22262_hline;
  _a4291t_54029 _i22261_v22261_f;
  void* _i22238_v22238_t;
  void* _i22237_v22237_iter__apos_2_mv_992;
  _pt54026* _i22236_v22236__f_uncurry;
  void* _i22235_v22235_t;
  void* _i22234_v22234_iter__apos_2_mv_992;
  _pt54026* _i22233_v22233__f_uncurry;
  _a5142t_54007 h;
  void* _i22231_v22231_t;
  void* _i22230_v22230_iter__apos_2_mv_992;
  void* _i22199_v22199_t;
  void* _i22198_v22198_iter__apos_2_mv_992;
  _pt54026* _i22197_v22197__f_uncurry;
  void* _i22129_v22129_t;
  void* _i22128_v22128_iter__apos_2_mv_992;
  _pt54026* _i22127_v22127__f_uncurry;
  void* _i22126_v22126_t;
  void* _i22125_v22125_iter__apos_2_mv_992;
  _pt54026* _i22124_v22124__f_uncurry;
  void* _i22122_v22122_t;
  void* _i22121_v22121_iter__apos_2_mv_992;
  void* acc;
  void* _i21721_v21721_aux__apos_2_mv_1004;
  void* init_uncurry;
  void* _i21719_v21719_x;
  void* _urv15920;
  _a2515t_54016 _genout_urv15988;
  void* files;
  int err;
  _a10907t_54017 eret;
  _a10907t_54017 e;
  _a10908t_54018 d;
  _a5142t_54007 _urv16212;
  void* rfi_mv_10606;
  _a5142t_54007 dname2;
  _a5142t_54007 result;
  _init_(FLX_FPAR_DECL_ONLY);
  _init_* clone();
  ::flx::rtl::con_t *call(::flx::rtl::con_t*);
  ::flx::rtl::con_t *resume();
};

//------------------------------
//PROCEDURE <21670>: _init_::rfi
struct rfi {
  FLX_FMEM_DECL
  _init_ *ptr_init_;

  void* _i21690_v21690_acc;
  void* _i21687_v21687_aux__apos_2_mv_1004;
  void* _i21686_v21686_init_uncurry;
  void* _i21685_v21685_x;
  void* _i21684_v21684__urv15920;
  void* _i21683_v21683_files;
  _a2515t_54016 _i21682_v21682__genout_urv15988;
  void* _i21681_v21681_files;
  int _i21680_v21680_err;
  _a10907t_54017 _i21679_v21679_eret;
  _a10907t_54017 _i21678_v21678_e;
  _a10908t_54018 _i21677_v21677_d;
  _a5142t_54007 _i21676_v21676__urv16212;
  void* _i21675_v21675_rfi_mv_10606;
  _us2 rfi_mv_10596;
  _a5142t_54007 _i21671_v21671_dname2;
  rfi  (FLX_FPAR_DECL _init_*);
  void* apply(_a5142t_54007 const &);
};

//------------------------------
//PROCEDURE <21688>: _init_::rfi::_lam_10617'2
struct _i21688_f21688__lam_10617__apos_2 {
  FLX_FMEM_DECL
  rfi *ptrrfi;
  _init_ *ptr_init_;

  void* _i21708_v21708_aux__apos_2_mv_982;
  void* x_uncurry;
  void* y;
  void* _urv13383;
  _us2 _urv13407;
  void* last;
  void* z;
  _us2 _genout_urv13471;
  int _i21700_v21700__lam_10617__apos_2_mv_10642;
  mode_t m;
  int _i21697_v21697_err;
  _a10768t_54055 b;
  _a5142t_54007 _urv13850;
  int _i21694_v21694__lam_10617__apos_2_mv_10635;
  _a5142t_54007 _i21693_v21693_d;
  _a5142t_54007 _i21692_v21692__lam_10617__apos_2_mv_10628;
  _a5142t_54007 _i21689_v21689_f;
  _i21688_f21688__lam_10617__apos_2  (FLX_FPAR_DECL rfi*, _init_*);
  void* apply(_a5142t_54007 const &);
};

//------------------------------
//PROCEDURE <21722>: _init_::_lam_10617'2
struct _i21722_f21722__lam_10617__apos_2 {
  FLX_FMEM_DECL
  _init_ *ptr_init_;

  void* _i43868_v43868_acc;
  void* _i43865_v43865_aux__apos_2_mv_1004;
  void* _i43864_v43864_init_uncurry;
  void* _i43863_v43863_x;
  void* _i43862_v43862__urv15920;
  _a2515t_54016 _i43860_v43860__genout_urv15988;
  void* _i43859_v43859_files;
  int _i43858_v43858_err;
  _a10907t_54017 _i43857_v43857_eret;
  _a10907t_54017 _i43856_v43856_e;
  _a10908t_54018 _i43855_v43855_d;
  _a5142t_54007 _i43854_v43854__urv16212;
  void* _i43853_v43853_rfi_mv_10606;
  _a5142t_54007 _i43851_v43851_dname2;
  void* _i21742_v21742_aux__apos_2_mv_982;
  void* _i21741_v21741_x_uncurry;
  void* _i21740_v21740_y;
  void* _i21739_v21739__urv13383;
  _us2 _i21738_v21738__urv13407;
  void* _i21737_v21737_last;
  void* _i21736_v21736_z;
  _us2 _i21735_v21735__genout_urv13471;
  int _i21734_v21734__lam_10617__apos_2_mv_10642;
  mode_t _i21732_v21732_m;
  int _i21731_v21731_err;
  _a10768t_54055 _i21730_v21730_b;
  _a5142t_54007 _i21729_v21729__urv13850;
  int _i21728_v21728__lam_10617__apos_2_mv_10635;
  _a5142t_54007 _i21727_v21727_d;
  _a5142t_54007 _i21726_v21726__lam_10617__apos_2_mv_10628;
  _a5142t_54007 _i21723_v21723_f;
  _i21722_f21722__lam_10617__apos_2  (FLX_FPAR_DECL _init_*);
  void* apply(_a5142t_54007 const &);
};

//------------------------------
//FUNCTION <41327>: println
struct println: _pt54026 {
  FLX_FMEM_DECL

  _a5142t_54007 _i41356_v41356_x;
  println(FLX_FPAR_DECL_ONLY);
  println* clone();
  ::flx::rtl::con_t *call(::flx::rtl::con_t*,_a5142t_54007 const &);
  ::flx::rtl::con_t *resume();
};

//------------------------------
//PURE C PROCEDURE <41362>: add
void* FLX_REGPARM add(FLX_FPAR_DECL  void*, _a5142t_54007);

//------------------------------
//PROCEDURE <43866>: _init_::_lam_10617'2::_lam_10617'2
struct _i43866_f43866__lam_10617__apos_2 {
  FLX_FMEM_DECL
  _i21722_f21722__lam_10617__apos_2 *ptr_i21722_f21722__lam_10617__apos_2;
  _init_ *ptr_init_;

  void* _i43884_v43884_aux__apos_2_mv_982;
  void* _i43883_v43883_x_uncurry;
  void* _i43882_v43882_y;
  void* _i43881_v43881__urv13383;
  _us2 _i43880_v43880__urv13407;
  void* _i43879_v43879_last;
  void* _i43878_v43878_z;
  _us2 _i43877_v43877__genout_urv13471;
  int _i43876_v43876__lam_10617__apos_2_mv_10642;
  mode_t _i43875_v43875_m;
  int _i43874_v43874_err;
  _a10768t_54055 _i43873_v43873_b;
  _a5142t_54007 _i43872_v43872__urv13850;
  int _i43871_v43871__lam_10617__apos_2_mv_10635;
  _a5142t_54007 _i43870_v43870_d;
  _a5142t_54007 _i43869_v43869__lam_10617__apos_2_mv_10628;
  _a5142t_54007 _i43867_v43867_f;
  _i43866_f43866__lam_10617__apos_2  (FLX_FPAR_DECL _i21722_f21722__lam_10617__apos_2*, _init_*);
  void* apply(_a5142t_54007 const &);
};

struct thread_frame_t {
  int argc;
  char **argv;
  FILE *flx_stdin;
  FILE *flx_stdout;
  FILE *flx_stderr;
  ::flx::gc::generic::gc_profile_t *gcp;
  ::flx::gc::generic::gc_shape_t *shape_list_head;
  thread_frame_t(
  );
  _a5142t_54007 INSTALL_ROOT_TOPDIR;
  _a5142t_54007 sep;
  _a4292t_54027 _i10968_v10968_f;
  void* docs;
  _a7480t_54012 re;

};

FLX_DCL_THREAD_FRAME

}} // namespace flxusr::mktutindex
using namespace ::flxusr::mktutindex;
//header complete
#endif