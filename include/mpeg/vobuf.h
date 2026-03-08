// https://github.com/Mikompilation/Himuro/blob/828c49053f0d0a67694ae678463dfa3b770b6ef3/include/sce/mpeg/vobuf.h#L29

#ifndef SCE_MPEG_VOBUF_H
#define SCE_MPEG_VOBUF_H

#include "common.h"
#include "mpeg/libmpeg.h"
#include "mpeg/defs.h"

#define N_GSBUF 2

#define VOBUF_STATUS_ 0
#define VOBUF_STATUS_TOPDONE 1
#define VOBUF_STATUS_FULL 2

typedef struct
{
    u_char v[MAX_WIDTH * MAX_HEIGHT * 4];
} VoData;

typedef struct
{
    int status;
    int dummy[15];
    u_int v[N_VOBUF][bound((N_LDTAGS + 100) * 4, 64)];
} VoTag;

typedef struct
{
    VoData *data;
    VoTag *tag;
    volatile int write;
    volatile int count;
    int size;
} VoBuf;

#endif // SCE_MPEG_VOBUF_H
