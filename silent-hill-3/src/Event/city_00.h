#ifndef CITY_00_H
#define CITY_00_H

#include "common.h"

typedef struct City00Struct
{
    struct City00Entry *unk0;
    __int128 unk10;
    __int128 unk20;
} City00Struct;

typedef struct City00Entry
{
    __int128 unk0;
    __int128 unk10;
    __int128 unk20;
    __int128 unk30;
} City00Entry;

City00Entry *shCharacterGetSubCharacter(int, int);
City00Entry *func_001C2C10(void *, __int128 *);

extern int D_01F6DB80_city_00;

#endif