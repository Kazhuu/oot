#include "z_en_fish.h"

#define FLAGS 0x00000000

#define THIS ((EnFish*)thisx)

void EnFish_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Draw(Actor* thisx, GlobalContext* globalCtx);

extern SkeletonHeader D_04018FE0;
extern AnimationHeader D_0401909C;

s32 D_80A17010[] = { 0x00000000 };
s32 D_80A17014[] = { 0x00000000 };
s32 D_80A17018[] = { 0x00000000 };

// sJntSphItemsInit
static ColliderJntSphItemInit D_80A1701C[1] = {
    {
        { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
        { 0, { { 0, 0, 0 }, 5 }, 100 },
    },
};

// D_80A17040
static ColliderJntSphInit sJntSphInit =
{
    { COLTYPE_UNK10, 0x00, 0x00, 0x39, 0x10, COLSHAPE_JNTSPH },
    1, D_80A1701C,
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

// sInitChain
InitChainEntry D_80A17070[] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 900, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 40, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 700, ICHAIN_STOP),
};

s32 D_80A17080[] = { 0x00000000, 0x3D23D70A, 0x3DB851EC };
s32 D_80A1708C[] = { 0x3F000000, 0x3DCCCCCD, 0x3E19999A, 0x00000000, 0x00000000 };

/*f32 func_80A15280(void *arg0, void *arg1) {*/
    /*f32 temp_f12;*/
    /*f32 temp_f2;*/

    /*temp_f2 = arg0->unk0 - arg1->unk0;*/
    /*temp_f12 = arg0->unk8 - arg1->unk8;*/
    /*return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);*/
/*}*/

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15280.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A152AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15310.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15374.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A153AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15444.s")

/*#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/EnFish_Init.s")*/

float D_80A17194 = 65535.5;
float D_80A17198 = 65535.5;

void EnFish_Init(Actor *thisx, GlobalContext *globalCtx) {
    s16 sp3A;
    EnFish* this = THIS;

    sp3A = this->actor.params;
    Actor_ProcessInitChain(&this->actor, D_80A17070);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_04018FE0, &D_0401909C, &this->limbDrawTable, &this->unk_21A, 7);
    Collider_InitJntSph(globalCtx, &this->collider);
    Collider_SetJntSph(globalCtx, &this->collider, &this->actor, &sJntSphInit, &this->colliderItems);
    this->actor.colChkInfo.mass = (u8)0x32U;
    this->unk24C = (s16) (s32) (Math_Rand_ZeroOne() * D_80A17194);
    this->unk24E = (s16) (s32) (Math_Rand_ZeroOne() * D_80A17198);
    if (sp3A == 0) {
        this->actor.flags = (u32) (this->actor.flags | 0x10);
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 8.0f);
        func_80A15F24(this);
        return;
    }
    if (sp3A == 1) {
        func_80A16618(this, 0.0f, ActorShadow_DrawFunc_Circle);
        return;
    }
    func_80A157A4(this, 0.0f, ActorShadow_DrawFunc_Circle);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/EnFish_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A155D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15688.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15774.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A157A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A157FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A158EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15944.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15AD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15B2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15D18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15F24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A15F84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A160BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16200.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A163DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16450.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16618.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16670.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16898.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A169C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16A64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16C68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/func_80A16DEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/EnFish_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fish/EnFish_Draw.s")
