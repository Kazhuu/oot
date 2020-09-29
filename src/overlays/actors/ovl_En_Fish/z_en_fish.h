#ifndef _Z_EN_FISH_H_
#define _Z_EN_FISH_H_

#include <ultra64.h>
#include <global.h>

struct EnFish;

typedef struct EnFish {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderJntSph collider;
    /* 0x016C */ ColliderJntSphItem colliderItems;
    /* 0x01AC */ SkelAnime skelAnime;
    /* 0x01F0 */ Vec3s limbDrawTable;
    /* 0x01F6 */ char unk_1F6[0x24];
    /* 0x021A */ Vec3s unk_21A;
    /* 0x0220 */ char unk_220[0xC];
    /* 0x022C */ s16 unk_22C;
    /* 0x022E */ s16 unk_22E;
    /* 0x0230 */ char unk_230[0x24];
} EnFish; // size = 0x0254

extern const ActorInit En_Fish_InitVars;

#endif
