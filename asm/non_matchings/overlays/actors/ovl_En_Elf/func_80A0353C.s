.late_rodata
glabel D_80A061D4
    .float 1500.0

.text
glabel func_80A0353C
/* 0190C 80A0353C 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 01910 80A03540 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01914 80A03544 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01918 80A03548 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0191C 80A0354C AFA5003C */  sw      $a1, 0x003C($sp)           
/* 01920 80A03550 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 01924 80A03554 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 01928 80A03558 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0192C 80A0355C 0C280A88 */  jal     func_80A02A20              
/* 01930 80A03560 8FA5003C */  lw      $a1, 0x003C($sp)           
/* 01934 80A03564 8E030118 */  lw      $v1, 0x0118($s0)           ## 00000118
/* 01938 80A03568 1060001B */  beq     $v1, $zero, .L80A035D8     
/* 0193C 80A0356C 00000000 */  nop
/* 01940 80A03570 8C6E0130 */  lw      $t6, 0x0130($v1)           ## 00000130
/* 01944 80A03574 11C00018 */  beq     $t6, $zero, .L80A035D8     
/* 01948 80A03578 00000000 */  nop
/* 0194C 80A0357C 8C780024 */  lw      $t8, 0x0024($v1)           ## 00000024
/* 01950 80A03580 27A5002C */  addiu   $a1, $sp, 0x002C           ## $a1 = FFFFFFF4
/* 01954 80A03584 3C0180A0 */  lui     $at, %hi(D_80A061D4)       ## $at = 80A00000
/* 01958 80A03588 ACB80000 */  sw      $t8, 0x0000($a1)           ## FFFFFFF4
/* 0195C 80A0358C 8C6F0028 */  lw      $t7, 0x0028($v1)           ## 00000028
/* 01960 80A03590 3C063E4C */  lui     $a2, 0x3E4C                ## $a2 = 3E4C0000
/* 01964 80A03594 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3E4CCCCD
/* 01968 80A03598 ACAF0004 */  sw      $t7, 0x0004($a1)           ## FFFFFFF8
/* 0196C 80A0359C 8C78002C */  lw      $t8, 0x002C($v1)           ## 0000002C
/* 01970 80A035A0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01974 80A035A4 ACB80008 */  sw      $t8, 0x0008($a1)           ## FFFFFFFC
/* 01978 80A035A8 C6060054 */  lwc1    $f6, 0x0054($s0)           ## 00000054
/* 0197C 80A035AC C42461D4 */  lwc1    $f4, %lo(D_80A061D4)($at)  
/* 01980 80A035B0 3C014220 */  lui     $at, 0x4220                ## $at = 42200000
/* 01984 80A035B4 44815000 */  mtc1    $at, $f10                  ## $f10 = 40.00
/* 01988 80A035B8 46062202 */  mul.s   $f8, $f4, $f6              
/* 0198C 80A035BC C7B20030 */  lwc1    $f18, 0x0030($sp)          
/* 01990 80A035C0 460A4400 */  add.s   $f16, $f8, $f10            
/* 01994 80A035C4 46109100 */  add.s   $f4, $f18, $f16            
/* 01998 80A035C8 0C280B26 */  jal     func_80A02C98              
/* 0199C 80A035CC E7A40030 */  swc1    $f4, 0x0030($sp)           
/* 019A0 80A035D0 10000004 */  beq     $zero, $zero, .L80A035E4   
/* 019A4 80A035D4 C60C0064 */  lwc1    $f12, 0x0064($s0)          ## 00000064
.L80A035D8:
/* 019A8 80A035D8 0C00B55C */  jal     Actor_Kill
              
/* 019AC 80A035DC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 019B0 80A035E0 C60C0064 */  lwc1    $f12, 0x0064($s0)          ## 00000064
.L80A035E4:
/* 019B4 80A035E4 0C034199 */  jal     atan2s
              
/* 019B8 80A035E8 C60E005C */  lwc1    $f14, 0x005C($s0)          ## 0000005C
/* 019BC 80A035EC A60202BC */  sh      $v0, 0x02BC($s0)           ## 000002BC
/* 019C0 80A035F0 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 019C4 80A035F4 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 019C8 80A035F8 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 019CC 80A035FC 03E00008 */  jr      $ra                        
/* 019D0 80A03600 00000000 */  nop
