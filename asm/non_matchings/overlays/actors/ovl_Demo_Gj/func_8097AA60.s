glabel func_8097AA60
/* 02130 8097AA60 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 02134 8097AA64 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02138 8097AA68 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 0213C 8097AA6C 0C25E606 */  jal     func_80979818              
/* 02140 8097AA70 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 02144 8097AA74 10400009 */  beq     $v0, $zero, .L8097AA9C     
/* 02148 8097AA78 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 0214C 8097AA7C 0C25E618 */  jal     func_80979860              
/* 02150 8097AA80 8FA5001C */  lw      $a1, 0x001C($sp)           
/* 02154 8097AA84 8FAF0018 */  lw      $t7, 0x0018($sp)           
/* 02158 8097AA88 240E000D */  addiu   $t6, $zero, 0x000D         ## $t6 = 0000000D
/* 0215C 8097AA8C 2418000E */  addiu   $t8, $zero, 0x000E         ## $t8 = 0000000E
/* 02160 8097AA90 ADEE0164 */  sw      $t6, 0x0164($t7)           ## 00000164
/* 02164 8097AA94 8FB90018 */  lw      $t9, 0x0018($sp)           
/* 02168 8097AA98 AF380168 */  sw      $t8, 0x0168($t9)           ## 00000168
.L8097AA9C:
/* 0216C 8097AA9C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 02170 8097AAA0 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 02174 8097AAA4 03E00008 */  jr      $ra                        
/* 02178 8097AAA8 00000000 */  nop
