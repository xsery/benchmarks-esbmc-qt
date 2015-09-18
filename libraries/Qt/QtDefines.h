#ifndef __QTDEFINES_H__
#define __QTDEFINES_H__

#include"../../definitions.h"

//#define QT_VERSION 0x050500

//#define QT_VERSION_CHECK(major, minor, patch) ((major<<16)|(minor<<8)|(patch))
#define slots
#define signals public

#undef LONG_MAX
#define LONG_MAX __LONG_MAX__

#undef ULONG_MAX
#define ULONG_MAX (LONG_MAX * 2UL + 1UL)

#ifndef Q_DECL_OVERRIDE
  #define Q_DECL_OVERRIDE
#endif

#endif /* _QTDEFINES_H__ */

