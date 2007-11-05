#line 3079 "./lpsrc/flx_rtl.pak"
#ifndef FLX_IOUTIL
#define FLX_IOUTIL
#include <string>
#include <cstdio>
#include "flx_rtl_config.hpp"

namespace flx { namespace rtl { namespace ioutil {
  RTL_EXTERN std::string load_file (std::FILE *);
  RTL_EXTERN std::string load_file (std::string);
  RTL_EXTERN std::string readln(std::FILE*);
  RTL_EXTERN void write (std::FILE *, std::string);
  RTL_EXTERN void writeln (std::FILE *, std::string);
}}}
#endif
