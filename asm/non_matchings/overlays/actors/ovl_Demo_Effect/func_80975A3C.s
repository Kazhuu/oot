glabel func_80975A3C
/* 04AEC 80975A3C 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 04AF0 80975A40 AFBF003C */  sw      $ra, 0x003C($sp)           
/* 04AF4 80975A44 AFB10038 */  sw      $s1, 0x0038($sp)           
/* 04AF8 80975A48 AFB00034 */  sw      $s0, 0x0034($sp)           
/* 04AFC 80975A4C AFA40078 */  sw      $a0, 0x0078($sp)           
/* 04B00 80975A50 848F0188 */  lh      $t7, 0x0188($a0)           ## 00000188
/* 04B04 80975A54 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 04B08 80975A58 3C068097 */  lui     $a2, %hi(D_80976B54)       ## $a2 = 80970000
/* 04B0C 80975A5C AFAF006C */  sw      $t7, 0x006C($sp)           
/* 04B10 80975A60 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 04B14 80975A64 24C66B54 */  addiu   $a2, $a2, %lo(D_80976B54)  ## $a2 = 80976B54
/* 04B18 80975A68 27A40058 */  addiu   $a0, $sp, 0x0058           ## $a0 = FFFFFFE0
/* 04B1C 80975A6C 24070B8C */  addiu   $a3, $zero, 0x0B8C         ## $a3 = 00000B8C
/* 04B20 80975A70 0C031AB1 */  jal     func_800C6AC4              
/* 04B24 80975A74 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 04B28 80975A78 0C024F61 */  jal     func_80093D84              
/* 04B2C 80975A7C 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 04B30 80975A80 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 04B34 80975A84 3C19FA00 */  lui     $t9, 0xFA00                ## $t9 = FA000000
/* 04B38 80975A88 37398080 */  ori     $t9, $t9, 0x8080           ## $t9 = FA008080
/* 04B3C 80975A8C 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 04B40 80975A90 AE1802D0 */  sw      $t8, 0x02D0($s0)           ## 000002D0
/* 04B44 80975A94 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 04B48 80975A98 8FA90078 */  lw      $t1, 0x0078($sp)           
/* 04B4C 80975A9C 3C01AAFF */  lui     $at, 0xAAFF                ## $at = AAFF0000
/* 04B50 80975AA0 3421FF00 */  ori     $at, $at, 0xFF00           ## $at = AAFFFF00
/* 04B54 80975AA4 912B0185 */  lbu     $t3, 0x0185($t1)           ## 00000185
/* 04B58 80975AA8 3C0F0064 */  lui     $t7, 0x0064                ## $t7 = 00640000
/* 04B5C 80975AAC 35EFFFFF */  ori     $t7, $t7, 0xFFFF           ## $t7 = 0064FFFF
/* 04B60 80975AB0 01616025 */  or      $t4, $t3, $at              ## $t4 = AAFFFF00
/* 04B64 80975AB4 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 04B68 80975AB8 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 04B6C 80975ABC 3C0EFB00 */  lui     $t6, 0xFB00                ## $t6 = FB000000
/* 04B70 80975AC0 3C19DA38 */  lui     $t9, 0xDA38                ## $t9 = DA380000
/* 04B74 80975AC4 244D0008 */  addiu   $t5, $v0, 0x0008           ## $t5 = 00000008
/* 04B78 80975AC8 AE0D02D0 */  sw      $t5, 0x02D0($s0)           ## 000002D0
/* 04B7C 80975ACC AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 04B80 80975AD0 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 04B84 80975AD4 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 04B88 80975AD8 37390003 */  ori     $t9, $t9, 0x0003           ## $t9 = DA380003
/* 04B8C 80975ADC 3C058097 */  lui     $a1, %hi(D_80976B68)       ## $a1 = 80970000
/* 04B90 80975AE0 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 04B94 80975AE4 AE1802D0 */  sw      $t8, 0x02D0($s0)           ## 000002D0
/* 04B98 80975AE8 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 04B9C 80975AEC 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 04BA0 80975AF0 24A56B68 */  addiu   $a1, $a1, %lo(D_80976B68)  ## $a1 = 80976B68
/* 04BA4 80975AF4 24060B93 */  addiu   $a2, $zero, 0x0B93         ## $a2 = 00000B93
/* 04BA8 80975AF8 0C0346A2 */  jal     Matrix_NewMtx              
/* 04BAC 80975AFC AFA2004C */  sw      $v0, 0x004C($sp)           
/* 04BB0 80975B00 8FA3004C */  lw      $v1, 0x004C($sp)           
/* 04BB4 80975B04 3C0ADB06 */  lui     $t2, 0xDB06                ## $t2 = DB060000
/* 04BB8 80975B08 354A0020 */  ori     $t2, $t2, 0x0020           ## $t2 = DB060020
/* 04BBC 80975B0C AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 04BC0 80975B10 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 04BC4 80975B14 8FA8006C */  lw      $t0, 0x006C($sp)           
/* 04BC8 80975B18 240D01FF */  addiu   $t5, $zero, 0x01FF         ## $t5 = 000001FF
/* 04BCC 80975B1C 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 04BD0 80975B20 AE0902D0 */  sw      $t1, 0x02D0($s0)           ## 000002D0
/* 04BD4 80975B24 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 04BD8 80975B28 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 04BDC 80975B2C 00083080 */  sll     $a2, $t0,  2               
/* 04BE0 80975B30 00085840 */  sll     $t3, $t0,  1               
/* 04BE4 80975B34 316C01FF */  andi    $t4, $t3, 0x01FF           ## $t4 = 00000000
/* 04BE8 80975B38 24090400 */  addiu   $t1, $zero, 0x0400         ## $t1 = 00000400
/* 04BEC 80975B3C 240E0010 */  addiu   $t6, $zero, 0x0010         ## $t6 = 00000010
/* 04BF0 80975B40 240F0080 */  addiu   $t7, $zero, 0x0080         ## $t7 = 00000080
/* 04BF4 80975B44 24180001 */  addiu   $t8, $zero, 0x0001         ## $t8 = 00000001
/* 04BF8 80975B48 24190008 */  addiu   $t9, $zero, 0x0008         ## $t9 = 00000008
/* 04BFC 80975B4C 00C83021 */  addu    $a2, $a2, $t0              
/* 04C00 80975B50 30C6003F */  andi    $a2, $a2, 0x003F           ## $a2 = 00000000
/* 04C04 80975B54 AFB90024 */  sw      $t9, 0x0024($sp)           
/* 04C08 80975B58 AFB80018 */  sw      $t8, 0x0018($sp)           
/* 04C0C 80975B5C AFAF0014 */  sw      $t7, 0x0014($sp)           
/* 04C10 80975B60 AFAE0010 */  sw      $t6, 0x0010($sp)           
/* 04C14 80975B64 AFA90028 */  sw      $t1, 0x0028($sp)           
/* 04C18 80975B68 01AC3823 */  subu    $a3, $t5, $t4              
/* 04C1C 80975B6C AFA00020 */  sw      $zero, 0x0020($sp)         
/* 04C20 80975B70 AFA0001C */  sw      $zero, 0x001C($sp)         
/* 04C24 80975B74 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 04C28 80975B78 0C0253D0 */  jal     Gfx_TwoTexScroll              
/* 04C2C 80975B7C AFA20048 */  sw      $v0, 0x0048($sp)           
/* 04C30 80975B80 8FA30048 */  lw      $v1, 0x0048($sp)           
/* 04C34 80975B84 3C0D0600 */  lui     $t5, 0x0600                ## $t5 = 06000000
/* 04C38 80975B88 25AD0190 */  addiu   $t5, $t5, 0x0190           ## $t5 = 06000190
/* 04C3C 80975B8C AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 04C40 80975B90 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 04C44 80975B94 3C0BDE00 */  lui     $t3, 0xDE00                ## $t3 = DE000000
/* 04C48 80975B98 3C068097 */  lui     $a2, %hi(D_80976B7C)       ## $a2 = 80970000
/* 04C4C 80975B9C 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 04C50 80975BA0 AE0A02D0 */  sw      $t2, 0x02D0($s0)           ## 000002D0
/* 04C54 80975BA4 AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 04C58 80975BA8 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 04C5C 80975BAC 8E250000 */  lw      $a1, 0x0000($s1)           ## 00000000
/* 04C60 80975BB0 24C66B7C */  addiu   $a2, $a2, %lo(D_80976B7C)  ## $a2 = 80976B7C
/* 04C64 80975BB4 27A40058 */  addiu   $a0, $sp, 0x0058           ## $a0 = FFFFFFE0
/* 04C68 80975BB8 0C031AD5 */  jal     func_800C6B54              
/* 04C6C 80975BBC 24070BA2 */  addiu   $a3, $zero, 0x0BA2         ## $a3 = 00000BA2
/* 04C70 80975BC0 8FBF003C */  lw      $ra, 0x003C($sp)           
/* 04C74 80975BC4 8FB00034 */  lw      $s0, 0x0034($sp)           
/* 04C78 80975BC8 8FB10038 */  lw      $s1, 0x0038($sp)           
/* 04C7C 80975BCC 03E00008 */  jr      $ra                        
/* 04C80 80975BD0 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000


