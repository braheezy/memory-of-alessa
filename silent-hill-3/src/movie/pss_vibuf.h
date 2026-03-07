// SDK video playback sample code.
// all credits to https://github.com/Mikompilation/Himuro/blob/828c49053f0d0a67694ae678463dfa3b770b6ef3/include/sce/mpeg/vibuf.h

#ifndef SCE_MPEG_VIBUF_H
#define SCE_MPEG_VIBUF_H

#include "libipu.h"
#include "common.h"
#include "eeregs.h"
#include "movie.h"
#include "eekernel.h"

#define TS_NONE -1

static inline void *DmaAddr(void *val)
{
    return (void *)((u_int)val & 0x0fffffff);
}

static inline void *UncAddr(void *val)
{
    return (void *)(((u_int)val & 0x0fffffff) | 0x20000000);
}

#define DMA_ID_REFE 0
#define DMA_ID_NEXT 2
#define DMA_ID_REF 3

#define VIBUF_ELM_SIZE 2048
#define VIBUF_SIZE 256
#define VIBUF_TS_SIZE (VIBUF_SIZE * 2)

#define TAG_ADDR(i) ((u_int)DmaAddr(f->tag + i))
#define DATA_ADDR(i) ((u_int)f->data + VIBUF_ELM_SIZE * (i))
#define WRAP_ADDR(addr) ((u_int)(f->data) + (((u_int)(addr) - (u_int)(f->data)) % (VIBUF_ELM_SIZE * f->n)))
#define IsInRegion(i, start, len, n) ((0 <= (((i) + (n) - (start)) % (n))) && ((((i) + (n) - (start)) % (n)) < (len)))

extern inline int IsPtsInRegion(int tgt, int pos, int len, int size)
{
    int tgt1 = (tgt + size - pos) % size;
    return tgt1 < len;
}

typedef struct
{ // 0x18
    /* 0x00 */ long int pts;
    /* 0x08 */ long int dts;
    /* 0x10 */ int pos;
    /* 0x14 */ int len;
} TimeStamp;

typedef struct
{ // 0x60
    /* 0x00 */ __int128 *data;
    /* 0x04 */ __int128 *tag;
    /* 0x08 */ int n;
    /* 0x0c */ int dmaStart;
    /* 0x10 */ int dmaN;
    /* 0x14 */ int readBytes;
    /* 0x18 */ int buffSize;
    /* 0x1c */ sceIpuDmaEnv env;
    /* 0x40 */ int sema;
    /* 0x44 */ int isActive;
    /* 0x48 */ long int totalBytes;
    /* 0x50 */ TimeStamp *ts;
    /* 0x54 */ int n_ts;
    /* 0x58 */ int count_ts;
    /* 0x5c */ int wt_ts;
} ViBuf;

int getFIFOindex(ViBuf *f, void *addr);
void setD3_CHCR(u_int val);
void setD4_CHCR(u_int val);
void scTag2(QWORD *q, void *addr, u_int id, u_int qwc);
int viBufCreate(ViBuf *f, __int128 *data, __int128 *tag, int size, TimeStamp *ts, int n_ts);
int viBufReset(ViBuf *f);
void viBufBeginPut(ViBuf *f, u_char **ptr0, int *len0, u_char **ptr1, int *len1);
void viBufEndPut(ViBuf *f, int size);
int viBufAddDMA(ViBuf *f);
int viBufStopDMA(ViBuf *f);
int viBufRestartDMA(ViBuf *f);
int viBufDelete(ViBuf *f);
int viBufIsActive(ViBuf *f);
int viBufCount(ViBuf *f);
void viBufFlush(ViBuf *f);
int viBufModifyPts(ViBuf *f, TimeStamp *new_ts);
int viBufPutTs(ViBuf *f, TimeStamp *ts);
int viBufGetTs(ViBuf *f, TimeStamp *ts);

#endif // SCE_MPEG_VIBUF_H
