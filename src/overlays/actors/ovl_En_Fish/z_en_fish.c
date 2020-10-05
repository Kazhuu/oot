#include "z_en_fish.h"

#define FLAGS 0x00000000

#define THIS ((EnFish*)thisx)

void EnFish_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80A15F84(EnFish*, GlobalContext*);
void func_80A16670(EnFish*, GlobalContext*);
void func_80A157FC(EnFish*, GlobalContext*);
void func_80A15944(EnFish*, GlobalContext*);
void func_80A15B2C(EnFish*, GlobalContext*);
void func_80A15D68(EnFish*, GlobalContext*);
void func_80A15F24(EnFish* this);
void func_80A16618(EnFish* this);
void func_80A157A4(EnFish* this);
void func_80A158EC(EnFish* this);
void func_80A15AD4(EnFish* this);
void func_80A15D18(EnFish* this);

extern SkeletonHeader D_04018FE0;
extern AnimationHeader D_0401909C;
extern AnimationHeader D_040185FC;

s32 D_80A17010[] = { 0x00000000 };
s32 D_80A17014[] = { 0x00000000 };
s32 D_80A17018[] = { 0x00000000 };

// D_80A1701C
static ColliderJntSphItemInit sJntSphItemsInit[1] = {
    {
        { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
        { 0, { { 0, 0, 0 }, 5 }, 100 },
    },
};

// D_80A17040
static ColliderJntSphInit sJntSphInit =
{
    { COLTYPE_UNK10, 0x00, 0x00, 0x39, 0x10, COLSHAPE_JNTSPH },
    1, sJntSphItemsInit,
};

const ActorInit En_Fish_InitVars = {
    ACTOR_EN_FISH,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnFish),
    (ActorFunc)EnFish_Init,
    (ActorFunc)EnFish_Destroy,
    (ActorFunc)EnFish_Update,
    (ActorFunc)EnFish_Draw,
};

// D_80A17070
static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 900, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 40, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 700, ICHAIN_STOP),
};

Vec3f D_80A17080 = { 0.0f, 0.04f, 0.09f };
Vec3f D_80A1708C = { 0.5f, 0.1f, 0.15f };

f32 func_80A15280(Vec3f* arg0, Vec3f *arg1) {
    f32 temp_f2 = arg0->x - arg1->x;
    f32 temp_f12 = arg0->z - arg1->z;
    return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
}

void func_80A152AC(EnFish* this) {
    SkelAnime_ChangeAnim(&this->skelAnime, &D_0401909C, 1.0f, 0.0f, SkelAnime_GetFrameCount(&D_0401909C.genericHeader), 1, 2.0f);
}

void func_80A15310(EnFish* this) {
    SkelAnime_ChangeAnim(&this->skelAnime, &D_040185FC, 1.0f, 0.0f, SkelAnime_GetFrameCount(&D_040185FC.genericHeader), 1, 2.0f);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15374.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A153AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15444.s")


void EnFish_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFish* this = THIS;

    s16 sp3A = this->actor.params;
    Actor_ProcessInitChain(&this->actor, sInitChain);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_04018FE0, &D_0401909C, &this->limbDrawTable, &this->unk_21A, 7);
    Collider_InitJntSph(globalCtx, &this->collider);
    Collider_SetJntSph(globalCtx, &this->collider, &this->actor, &sJntSphInit, &this->colliderItems);
    this->actor.colChkInfo.mass = 0x32U;
    this->unk24C = Math_Rand_ZeroOne() * 65535.5f;
    this->unk24E = Math_Rand_ZeroOne() * 65535.5f;
    if (sp3A == 0) {
        this->actor.flags = this->actor.flags | 0x10;
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 8.0f);
        func_80A15F24(this);
        return;
    }
    if (sp3A == 1) {
        func_80A16618(this);
        return;
    }
    func_80A157A4(this);
}

void EnFish_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    Collider_DestroyJntSph(globalCtx, &THIS->collider);
}

void func_80A155D0(EnFish* this) {
    this->actor.shape.unk_08 += Math_Sins(this->unk24C) * 10.0f + Math_Sins(this->unk24E) * 5.0f;
    this->actor.shape.unk_08 = CLAMP(this->actor.shape.unk_08, -200.0f, 200.0f);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15688.s")

s32 func_80A15774(EnFish* this, GlobalContext* globalCtx) {
    return this->actor.xzDistFromLink < 60.0f;
}

void func_80A157A4(EnFish* this) {
    this->actor.gravity = 0.0f;
    this->actor.minVelocityY = 0.0f;
    this = this;
    this->unk_248 = Math_Rand_S16Offset(5, 35);
    this->unk_250 = NULL;
    func_80A152AC(this);
    this->actionFunc = func_80A157FC;
}

void func_80A157FC(EnFish* this, GlobalContext* globalCtx) {
    f32 temp_f0;

    func_80A155D0(this);
    Math_SmoothScaleMaxMinF(&this->actor.speedXZ, 0.0f, 0.05f, 0.3f, 0.0f);
    temp_f0 = this->actor.speedXZ * 1.4f + 0.8f;
    if (2.0f < temp_f0) {
        this->skelAnime.animPlaybackSpeed = 2.0f;
    } else {
        this->skelAnime.animPlaybackSpeed = temp_f0;
    }
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    this->actor.shape.rot.y = this->actor.posRot.rot.y;
    if (this->unk_248 <= 0) {
        func_80A158EC(this);
        return;
    }
    if (&this->actor == this->actor.child) {
        func_80A15D18(this);
        return;
    }
    if (func_80A15774(this, globalCtx) != 0) {
        func_80A15AD4(this);
    }
}

void func_80A158EC(EnFish* this) {
    this->actor.gravity = 0.0f;
    this->actor.minVelocityY = 0.0f;
    this->unk_248 = Math_Rand_S16Offset(15, 45);
    this->unk_250 = NULL;
    func_80A152AC(this);
    this->actionFunc = func_80A15944;
}

void func_80A15944(EnFish* this, GlobalContext* globalCtx) {
    f32 temp;

    func_80A155D0(this);
    Math_SmoothScaleMaxMinF(&this->actor.speedXZ, 1.8f, 0.08f, 0.4f, 0.0f);
    if (6400.0f < func_80A15280(&this->actor.posRot.pos, &this->actor.initPosRot.pos) || this->unk_248 < 4) {
        func_80077B58(&this->actor.posRot.rot.y, Math_Vec3f_Yaw(&this->actor.posRot.pos, &this->actor.initPosRot.pos), 3000);
    } else {
        if (this->actor.child != 0) {
            if (&this->actor != this->actor.child) {
                func_80077B58(&this->actor.posRot.rot.y, Math_Vec3f_Yaw(&this->actor.posRot.pos, &this->actor.child->posRot.pos), 3000);
            }
        }
    }
    this->actor.shape.rot.y = this->actor.posRot.rot.y;
    temp = this->actor.speedXZ * 1.5f + 0.8f;
    this->skelAnime.animPlaybackSpeed = CLAMP_MAX(temp, 4.0f);
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if (this->unk_248 <= 0) {
        func_80A157A4(this);
        return;
    }
    if (&this->actor == this->actor.child) {
        func_80A15D18(this);
        return;
    }
    if (func_80A15774(this, globalCtx) != 0) {
        func_80A15AD4(this);
    }
}

void func_80A15AD4(EnFish* this) {
    this->actor.gravity = 0.0f;
    this->actor.minVelocityY = 0.0f;
    this->unk_248 = Math_Rand_S16Offset(10, 40);
    this->unk_250 = NULL;
    func_80A152AC(this);
    this->actionFunc = func_80A15B2C;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15B2C.s")

void func_80A15D18(EnFish* this) {
    this->actor.gravity = 0.0f;
    this->actor.minVelocityY = 0.0f;
    func_80A152AC(this);
    this->unk_248 = Math_Rand_S16Offset(10, 40);
    this->unk_250 = NULL;
    this->actionFunc = func_80A15D68;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15D68.s")

void func_80A15F24(EnFish* this) {
    this->actor.gravity = -1.0f;
    this->actor.minVelocityY = -10.0f;
    this->actor.shape.unk_08 = 0.0f;
    func_80A15310(this);
    this->unk_250 = 5; // What is this?
    this->actionFunc = func_80A15F84;
    this->unk_248 = 300;
}

void func_80A15F84(EnFish* this, GlobalContext* globalCtx) {
    Math_SmoothScaleMaxMinF(&this->actor.speedXZ, 0.0f, 0.1f, 0.1f, 0.0f);
    func_80077B58(&this->actor.posRot.rot.x, 16384, 100);
    func_80077B58(&this->actor.posRot.rot.z, -16384, 100);
    this->actor.shape.rot.x = this->actor.posRot.rot.x;
    this->actor.shape.rot.y = this->actor.posRot.rot.y;
    this->actor.shape.rot.z = this->actor.posRot.rot.z;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((this->actor.bgCheckFlags & 1) != 0) {
        this->unk_248 = 400;
        func_80A160BC(this);
        return;
    }
    if ((this->actor.bgCheckFlags & 0x20) != 0) {
        func_80A163DC(this);
        return;
    }
    if (this->unk_248 <= 0) {
        if (this->actor.params == 0) {
            if (this->actor.groundY < -31990.0f) {
                osSyncPrintf((const char *) "\x1b[43;30m");
                osSyncPrintf((const char *) "BG 抜け？ Actor_delete します(%s %d)\n", "../z_en_sakana.c", 822);
                osSyncPrintf((const char *) "\x1b[m");
                Actor_Kill(&this->actor);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A160BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16200.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A163DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16450.s")

void func_80A16618(EnFish* this) {
    this->actor.gravity = 0.0f;
    this->actor.minVelocityY = 0.0f;
    this->unk_248 = Math_Rand_S16Offset(5, 35);
    this->unk_250 = NULL;
    func_80A152AC(this);
    this->actionFunc = func_80A16670;
}

void func_80A16670(EnFish* this, GlobalContext* globalCtx) {
    f32 temp_f2;
    u32 frames; // important
    Vec3f* phi_v0;
    s32 pad;
    f32 sp44; // important
    s32 pad1;

    frames = globalCtx->gameplayFrames;
    if (this->actor.xzDistFromLink < 60.0f) {
        if (this->unk_248 < 0xC) {
            phi_v0 = &D_80A1708C;
        } else {
            phi_v0 = &D_80A17080;
        }
    } else {
        if (this->unk_248 < 4) {
            phi_v0 = &D_80A1708C;
        }
        else {
            phi_v0 = &D_80A17080;
        }
    }
    func_80A155D0(this);
    Math_SmoothScaleMaxMinF(&this->actor.speedXZ, phi_v0->x, phi_v0->y, phi_v0->z, 0.0f);
    sp44 = 0.0f;
    if (225.0f < func_80A15280(&this->actor.posRot.pos, &this->actor.initPosRot.pos)) {
        if (Math_ApproxUpdateScaledS(&this->actor.posRot.rot.y, Math_Vec3f_Yaw(&this->actor.posRot.pos, &this->actor.initPosRot.pos), 0xC8) == 0) {
            sp44 = 0.5f;
        }
    } else if (this->unk_248 < 4 && Math_ApproxUpdateScaledS(&this->actor.posRot.rot.y, frames << 7, 0x64) == 0) {
        sp44 = 0.5f;
    }
    this->actor.shape.rot.y = this->actor.posRot.rot.y;
    temp_f2 = this->actor.speedXZ * 1.2f + 0.2f + sp44;
    this->skelAnime.animPlaybackSpeed = CLAMP(temp_f2, 1.5f, 0.5);
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if (this->unk_248 <= 0) {
        this->unk_248 = Math_Rand_S16Offset(5, 0x50);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16898.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A169C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16A64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16C68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16DEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/EnFish_Update.s")

void EnFish_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFish* this = THIS;
    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawSV(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount, 0, 0, 0);
    func_800628A4(0, &this->collider);
}
