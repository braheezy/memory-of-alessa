#ifndef SCE_MPEG_DEFS_H
#define SCE_MPEG_DEFS_H

#include "common.h"

#define MAX_WIDTH 640
#define MAX_HEIGHT 480

#define bound(val, x) ((((val) + (x) - 1) / (x)) * (x))

#define N_VOBUF 2

#define N_LDTAGS (MAX_WIDTH / 16 * MAX_HEIGHT / 16 * 6 + 10)

#define TS_NONE -1

static inline void *DmaAddr(void *val)
{
    return (void *)((u_int)val & 0x0fffffff);
}

static inline void *UncAddr(void *val)
{
    return (void *)(((u_int)val & 0x0fffffff) | 0x20000000);
}

#endif // SCE_MPEG_DEFS_H