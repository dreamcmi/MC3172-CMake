
/*--------------------------------------------------------------------------
thread_start.c

****************************************
**  Copyright  (C)    2021-2022   **
**  Web:              http://rothd.cn   **
****************************************
--------------------------------------------------------------------------*/
#ifndef THREAD_START_C
#define THREAD_START_C
#include "./MC3172.h"
#include "./thread_config.h"



void thread1_initial(void)
{
#ifdef ROTHD_THREAD1_VALID
extern void thread1_main(void);
    rothd_set_sp_const(ROTHD_THREAD1_STACKCFG_VALUE|0x20000000);
    thread1_main();
#endif
}
void thread2_initial(void)
{
#ifdef ROTHD_THREAD2_VALID
extern void thread2_main(void);
    rothd_set_sp_const(ROTHD_THREAD2_STACKCFG_VALUE|0x20000000);
    thread2_main();
#endif
}
void thread3_initial(void)
{
#ifdef ROTHD_THREAD3_VALID
extern void thread3_main(void);
    rothd_set_sp_const(ROTHD_THREAD3_STACKCFG_VALUE|0x20000000);
    thread3_main();
#endif
}
void thread4_initial(void)
{
#ifdef ROTHD_THREAD4_VALID
extern void thread4_main(void);
    rothd_set_sp_const(ROTHD_THREAD4_STACKCFG_VALUE|0x20000000);
    thread4_main();
#endif
}
void thread5_initial(void)
{
#ifdef ROTHD_THREAD5_VALID
extern void thread5_main(void);
    rothd_set_sp_const(ROTHD_THREAD5_STACKCFG_VALUE|0x20000000);
    thread5_main();
#endif
}
void thread6_initial(void)
{
#ifdef ROTHD_THREAD6_VALID
extern void thread6_main(void);
    rothd_set_sp_const(ROTHD_THREAD6_STACKCFG_VALUE|0x20000000);
    thread6_main();
#endif
}
void thread7_initial(void)
{
#ifdef ROTHD_THREAD7_VALID
extern void thread7_main(void);
    rothd_set_sp_const(ROTHD_THREAD7_STACKCFG_VALUE|0x20000000);
    thread7_main();
#endif
}
void thread8_initial(void)
{
#ifdef ROTHD_THREAD8_VALID
extern void thread8_main(void);
    rothd_set_sp_const(ROTHD_THREAD8_STACKCFG_VALUE|0x20000000);
    thread8_main();
#endif
}
void thread9_initial(void)
{
#ifdef ROTHD_THREAD9_VALID
extern void thread9_main(void);
    rothd_set_sp_const(ROTHD_THREAD9_STACKCFG_VALUE|0x20000000);
    thread9_main();
#endif
}
void thread10_initial(void)
{
#ifdef ROTHD_THREAD10_VALID
extern void thread10_main(void);
    rothd_set_sp_const(ROTHD_THREAD10_STACKCFG_VALUE|0x20000000);
    thread10_main();
#endif
}
void thread11_initial(void)
{
#ifdef ROTHD_THREAD11_VALID
extern void thread11_main(void);
    rothd_set_sp_const(ROTHD_THREAD11_STACKCFG_VALUE|0x20000000);
    thread11_main();
#endif
}
void thread12_initial(void)
{
#ifdef ROTHD_THREAD12_VALID
extern void thread12_main(void);
    rothd_set_sp_const(ROTHD_THREAD12_STACKCFG_VALUE|0x20000000);
    thread12_main();
#endif
}
void thread13_initial(void)
{
#ifdef ROTHD_THREAD13_VALID
extern void thread13_main(void);
    rothd_set_sp_const(ROTHD_THREAD13_STACKCFG_VALUE|0x20000000);
    thread13_main();
#endif
}
void thread14_initial(void)
{
#ifdef ROTHD_THREAD14_VALID
extern void thread14_main(void);
    rothd_set_sp_const(ROTHD_THREAD14_STACKCFG_VALUE|0x20000000);
    thread14_main();
#endif
}
void thread15_initial(void)
{
#ifdef ROTHD_THREAD15_VALID
extern void thread15_main(void);
    rothd_set_sp_const(ROTHD_THREAD15_STACKCFG_VALUE|0x20000000);
    thread15_main();
#endif
}
void thread16_initial(void)
{
#ifdef ROTHD_THREAD16_VALID
extern void thread16_main(void);
    rothd_set_sp_const(ROTHD_THREAD16_STACKCFG_VALUE|0x20000000);
    thread16_main();
#endif
}
void thread17_initial(void)
{
#ifdef ROTHD_THREAD17_VALID
extern void thread17_main(void);
    rothd_set_sp_const(ROTHD_THREAD17_STACKCFG_VALUE|0x20000000);
    thread17_main();
#endif
}
void thread18_initial(void)
{
#ifdef ROTHD_THREAD18_VALID
extern void thread18_main(void);
    rothd_set_sp_const(ROTHD_THREAD18_STACKCFG_VALUE|0x20000000);
    thread18_main();
#endif
}
void thread19_initial(void)
{
#ifdef ROTHD_THREAD19_VALID
extern void thread19_main(void);
    rothd_set_sp_const(ROTHD_THREAD19_STACKCFG_VALUE|0x20000000);
    thread19_main();
#endif
}
void thread20_initial(void)
{
#ifdef ROTHD_THREAD20_VALID
extern void thread20_main(void);
    rothd_set_sp_const(ROTHD_THREAD20_STACKCFG_VALUE|0x20000000);
    thread20_main();
#endif
}
void thread21_initial(void)
{
#ifdef ROTHD_THREAD21_VALID
extern void thread21_main(void);
    rothd_set_sp_const(ROTHD_THREAD21_STACKCFG_VALUE|0x20000000);
    thread21_main();
#endif
}
void thread22_initial(void)
{
#ifdef ROTHD_THREAD22_VALID
extern void thread22_main(void);
    rothd_set_sp_const(ROTHD_THREAD22_STACKCFG_VALUE|0x20000000);
    thread22_main();
#endif
}
void thread23_initial(void)
{
#ifdef ROTHD_THREAD23_VALID
extern void thread23_main(void);
    rothd_set_sp_const(ROTHD_THREAD23_STACKCFG_VALUE|0x20000000);
    thread23_main();
#endif
}
void thread24_initial(void)
{
#ifdef ROTHD_THREAD24_VALID
extern void thread24_main(void);
    rothd_set_sp_const(ROTHD_THREAD24_STACKCFG_VALUE|0x20000000);
    thread24_main();
#endif
}
void thread25_initial(void)
{
#ifdef ROTHD_THREAD25_VALID
extern void thread25_main(void);
    rothd_set_sp_const(ROTHD_THREAD25_STACKCFG_VALUE|0x20000000);
    thread25_main();
#endif
}
void thread26_initial(void)
{
#ifdef ROTHD_THREAD26_VALID
extern void thread26_main(void);
    rothd_set_sp_const(ROTHD_THREAD26_STACKCFG_VALUE|0x20000000);
    thread26_main();
#endif
}
void thread27_initial(void)
{
#ifdef ROTHD_THREAD27_VALID
extern void thread27_main(void);
    rothd_set_sp_const(ROTHD_THREAD27_STACKCFG_VALUE|0x20000000);
    thread27_main();
#endif
}
void thread28_initial(void)
{
#ifdef ROTHD_THREAD28_VALID
extern void thread28_main(void);
    rothd_set_sp_const(ROTHD_THREAD28_STACKCFG_VALUE|0x20000000);
    thread28_main();
#endif
}
void thread29_initial(void)
{
#ifdef ROTHD_THREAD29_VALID
extern void thread29_main(void);
    rothd_set_sp_const(ROTHD_THREAD29_STACKCFG_VALUE|0x20000000);
    thread29_main();
#endif
}
void thread30_initial(void)
{
#ifdef ROTHD_THREAD30_VALID
extern void thread30_main(void);
    rothd_set_sp_const(ROTHD_THREAD30_STACKCFG_VALUE|0x20000000);
    thread30_main();
#endif
}
void thread31_initial(void)
{
#ifdef ROTHD_THREAD31_VALID
extern void thread31_main(void);
    rothd_set_sp_const(ROTHD_THREAD31_STACKCFG_VALUE|0x20000000);
    thread31_main();
#endif
}
void thread32_initial(void)
{
#ifdef ROTHD_THREAD32_VALID
extern void thread32_main(void);
    rothd_set_sp_const(ROTHD_THREAD32_STACKCFG_VALUE|0x20000000);
    thread32_main();
#endif
}
void thread33_initial(void)
{
#ifdef ROTHD_THREAD33_VALID
extern void thread33_main(void);
    rothd_set_sp_const(ROTHD_THREAD33_STACKCFG_VALUE|0x20000000);
    thread33_main();
#endif
}
void thread34_initial(void)
{
#ifdef ROTHD_THREAD34_VALID
extern void thread34_main(void);
    rothd_set_sp_const(ROTHD_THREAD34_STACKCFG_VALUE|0x20000000);
    thread34_main();
#endif
}
void thread35_initial(void)
{
#ifdef ROTHD_THREAD35_VALID
extern void thread35_main(void);
    rothd_set_sp_const(ROTHD_THREAD35_STACKCFG_VALUE|0x20000000);
    thread35_main();
#endif
}
void thread36_initial(void)
{
#ifdef ROTHD_THREAD36_VALID
extern void thread36_main(void);
    rothd_set_sp_const(ROTHD_THREAD36_STACKCFG_VALUE|0x20000000);
    thread36_main();
#endif
}
void thread37_initial(void)
{
#ifdef ROTHD_THREAD37_VALID
extern void thread37_main(void);
    rothd_set_sp_const(ROTHD_THREAD37_STACKCFG_VALUE|0x20000000);
    thread37_main();
#endif
}
void thread38_initial(void)
{
#ifdef ROTHD_THREAD38_VALID
extern void thread38_main(void);
    rothd_set_sp_const(ROTHD_THREAD38_STACKCFG_VALUE|0x20000000);
    thread38_main();
#endif
}
void thread39_initial(void)
{
#ifdef ROTHD_THREAD39_VALID
extern void thread39_main(void);
    rothd_set_sp_const(ROTHD_THREAD39_STACKCFG_VALUE|0x20000000);
    thread39_main();
#endif
}
void thread40_initial(void)
{
#ifdef ROTHD_THREAD40_VALID
extern void thread40_main(void);
    rothd_set_sp_const(ROTHD_THREAD40_STACKCFG_VALUE|0x20000000);
    thread40_main();
#endif
}
void thread41_initial(void)
{
#ifdef ROTHD_THREAD41_VALID
extern void thread41_main(void);
    rothd_set_sp_const(ROTHD_THREAD41_STACKCFG_VALUE|0x20000000);
    thread41_main();
#endif
}
void thread42_initial(void)
{
#ifdef ROTHD_THREAD42_VALID
extern void thread42_main(void);
    rothd_set_sp_const(ROTHD_THREAD42_STACKCFG_VALUE|0x20000000);
    thread42_main();
#endif
}
void thread43_initial(void)
{
#ifdef ROTHD_THREAD43_VALID
extern void thread43_main(void);
    rothd_set_sp_const(ROTHD_THREAD43_STACKCFG_VALUE|0x20000000);
    thread43_main();
#endif
}
void thread44_initial(void)
{
#ifdef ROTHD_THREAD44_VALID
extern void thread44_main(void);
    rothd_set_sp_const(ROTHD_THREAD44_STACKCFG_VALUE|0x20000000);
    thread44_main();
#endif
}
void thread45_initial(void)
{
#ifdef ROTHD_THREAD45_VALID
extern void thread45_main(void);
    rothd_set_sp_const(ROTHD_THREAD45_STACKCFG_VALUE|0x20000000);
    thread45_main();
#endif
}
void thread46_initial(void)
{
#ifdef ROTHD_THREAD46_VALID
extern void thread46_main(void);
    rothd_set_sp_const(ROTHD_THREAD46_STACKCFG_VALUE|0x20000000);
    thread46_main();
#endif
}
void thread47_initial(void)
{
#ifdef ROTHD_THREAD47_VALID
extern void thread47_main(void);
    rothd_set_sp_const(ROTHD_THREAD47_STACKCFG_VALUE|0x20000000);
    thread47_main();
#endif
}
void thread48_initial(void)
{
#ifdef ROTHD_THREAD48_VALID
extern void thread48_main(void);
    rothd_set_sp_const(ROTHD_THREAD48_STACKCFG_VALUE|0x20000000);
    thread48_main();
#endif
}
void thread49_initial(void)
{
#ifdef ROTHD_THREAD49_VALID
extern void thread49_main(void);
    rothd_set_sp_const(ROTHD_THREAD49_STACKCFG_VALUE|0x20000000);
    thread49_main();
#endif
}
void thread50_initial(void)
{
#ifdef ROTHD_THREAD50_VALID
extern void thread50_main(void);
    rothd_set_sp_const(ROTHD_THREAD50_STACKCFG_VALUE|0x20000000);
    thread50_main();
#endif
}
void thread51_initial(void)
{
#ifdef ROTHD_THREAD51_VALID
extern void thread51_main(void);
    rothd_set_sp_const(ROTHD_THREAD51_STACKCFG_VALUE|0x20000000);
    thread51_main();
#endif
}
void thread52_initial(void)
{
#ifdef ROTHD_THREAD52_VALID
extern void thread52_main(void);
    rothd_set_sp_const(ROTHD_THREAD52_STACKCFG_VALUE|0x20000000);
    thread52_main();
#endif
}
void thread53_initial(void)
{
#ifdef ROTHD_THREAD53_VALID
extern void thread53_main(void);
    rothd_set_sp_const(ROTHD_THREAD53_STACKCFG_VALUE|0x20000000);
    thread53_main();
#endif
}
void thread54_initial(void)
{
#ifdef ROTHD_THREAD54_VALID
extern void thread54_main(void);
    rothd_set_sp_const(ROTHD_THREAD54_STACKCFG_VALUE|0x20000000);
    thread54_main();
#endif
}
void thread55_initial(void)
{
#ifdef ROTHD_THREAD55_VALID
extern void thread55_main(void);
    rothd_set_sp_const(ROTHD_THREAD55_STACKCFG_VALUE|0x20000000);
    thread55_main();
#endif
}
void thread56_initial(void)
{
#ifdef ROTHD_THREAD56_VALID
extern void thread56_main(void);
    rothd_set_sp_const(ROTHD_THREAD56_STACKCFG_VALUE|0x20000000);
    thread56_main();
#endif
}
void thread57_initial(void)
{
#ifdef ROTHD_THREAD57_VALID
extern void thread57_main(void);
    rothd_set_sp_const(ROTHD_THREAD57_STACKCFG_VALUE|0x20000000);
    thread57_main();
#endif
}
void thread58_initial(void)
{
#ifdef ROTHD_THREAD58_VALID
extern void thread58_main(void);
    rothd_set_sp_const(ROTHD_THREAD58_STACKCFG_VALUE|0x20000000);
    thread58_main();
#endif
}
void thread59_initial(void)
{
#ifdef ROTHD_THREAD59_VALID
extern void thread59_main(void);
    rothd_set_sp_const(ROTHD_THREAD59_STACKCFG_VALUE|0x20000000);
    thread59_main();
#endif
}
void thread60_initial(void)
{
#ifdef ROTHD_THREAD60_VALID
extern void thread60_main(void);
    rothd_set_sp_const(ROTHD_THREAD60_STACKCFG_VALUE|0x20000000);
    thread60_main();
#endif
}
void thread61_initial(void)
{
#ifdef ROTHD_THREAD61_VALID
extern void thread61_main(void);
    rothd_set_sp_const(ROTHD_THREAD61_STACKCFG_VALUE|0x20000000);
    thread61_main();
#endif
}
void thread62_initial(void)
{
#ifdef ROTHD_THREAD62_VALID
extern void thread62_main(void);
    rothd_set_sp_const(ROTHD_THREAD62_STACKCFG_VALUE|0x20000000);
    thread62_main();
#endif
}
void thread63_initial(void)
{
#ifdef ROTHD_THREAD63_VALID
extern void thread63_main(void);
    rothd_set_sp_const(ROTHD_THREAD63_STACKCFG_VALUE|0x20000000);
    thread63_main();
#endif
}





void thread0_initial(void)
{
    rothd_set_sp_const((ROTHD_DATA_SPACE_VALUE|0x20000000)-32);
#if ROTHD_DATA_RAM_VALUE==32768*3
    DATA_RAM_RATIO=0x60;
#endif
#if ROTHD_DATA_RAM_VALUE==32768*2
    DATA_RAM_RATIO=0x40;
#endif
#if ROTHD_DATA_RAM_VALUE==32768
    DATA_RAM_RATIO=0x20;
#endif


#if ROTHD_COLCK_SOURCE_SEL==0
    (*(volatile u32*)(0x50050108))=0x00200003;
    (*(volatile u32*)(0x50050108))=0x00200007;
    (*(volatile u32*)(0x50050108))=0x0020000f;
    (*(volatile u32*)(0x50050108))=0x0020010f;
#endif
#if ROTHD_COLCK_SOURCE_SEL==1
    (*(volatile u32*)(0x50050108))=0x00300003;
    (*(volatile u32*)(0x50050108))=0x00300007;
    (*(volatile u32*)(0x50050108))=0x0030000f;
    (*(volatile u32*)(0x50050108))=0x0030010f;
#endif
#if ROTHD_COLCK_SOURCE_SEL==2
    (*(volatile u32*)(0x50050108))=0x00000003;
    (*(volatile u32*)(0x50050108))=0x00000007;
    (*(volatile u32*)(0x50050108))=0x0000000f;
    (*(volatile u32*)(0x50050108))=0x0000010f;
#endif
#if ROTHD_COLCK_SOURCE_SEL==3
    (*(volatile u32*)(0x50050108))=0x00100003;
    (*(volatile u32*)(0x50050108))=0x00100007;
    (*(volatile u32*)(0x50050108))=0x0010000f;
    (*(volatile u32*)(0x50050108))=0x0010010f;
#endif



#ifdef ROTHD_THREAD1_VALID
    *(int*)(THD_TS_ADDR+8)=ROTHD_THREAD1_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD2_VALID
    *(int*)(THD_TS_ADDR+16)=ROTHD_THREAD2_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD3_VALID
    *(int*)(THD_TS_ADDR+24)=ROTHD_THREAD3_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD5_VALID
    *(int*)(THD_TS_ADDR+40)=ROTHD_THREAD5_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD6_VALID
    *(int*)(THD_TS_ADDR+48)=ROTHD_THREAD6_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD7_VALID
    *(int*)(THD_TS_ADDR+56)=ROTHD_THREAD7_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD9_VALID
    *(int*)(THD_TS_ADDR+72)=ROTHD_THREAD9_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD10_VALID
    *(int*)(THD_TS_ADDR+80)=ROTHD_THREAD10_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD11_VALID
    *(int*)(THD_TS_ADDR+88)=ROTHD_THREAD11_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD13_VALID
    *(int*)(THD_TS_ADDR+104)=ROTHD_THREAD13_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD14_VALID
    *(int*)(THD_TS_ADDR+112)=ROTHD_THREAD14_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD15_VALID
    *(int*)(THD_TS_ADDR+120)=ROTHD_THREAD15_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD17_VALID
    *(int*)(THD_TS_ADDR+136)=ROTHD_THREAD17_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD18_VALID
    *(int*)(THD_TS_ADDR+144)=ROTHD_THREAD18_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD19_VALID
    *(int*)(THD_TS_ADDR+152)=ROTHD_THREAD19_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD21_VALID
    *(int*)(THD_TS_ADDR+168)=ROTHD_THREAD21_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD22_VALID
    *(int*)(THD_TS_ADDR+176)=ROTHD_THREAD22_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD23_VALID
    *(int*)(THD_TS_ADDR+184)=ROTHD_THREAD23_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD25_VALID
    *(int*)(THD_TS_ADDR+200)=ROTHD_THREAD25_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD26_VALID
    *(int*)(THD_TS_ADDR+208)=ROTHD_THREAD26_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD27_VALID
    *(int*)(THD_TS_ADDR+216)=ROTHD_THREAD27_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD29_VALID
    *(int*)(THD_TS_ADDR+232)=ROTHD_THREAD29_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD30_VALID
    *(int*)(THD_TS_ADDR+240)=ROTHD_THREAD30_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD31_VALID
    *(int*)(THD_TS_ADDR+248)=ROTHD_THREAD31_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD33_VALID
    *(int*)(THD_TS_ADDR+264)=ROTHD_THREAD33_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD34_VALID
    *(int*)(THD_TS_ADDR+272)=ROTHD_THREAD34_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD35_VALID
    *(int*)(THD_TS_ADDR+280)=ROTHD_THREAD35_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD37_VALID
    *(int*)(THD_TS_ADDR+296)=ROTHD_THREAD37_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD38_VALID
    *(int*)(THD_TS_ADDR+304)=ROTHD_THREAD38_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD39_VALID
    *(int*)(THD_TS_ADDR+312)=ROTHD_THREAD39_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD41_VALID
    *(int*)(THD_TS_ADDR+328)=ROTHD_THREAD41_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD42_VALID
    *(int*)(THD_TS_ADDR+336)=ROTHD_THREAD42_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD43_VALID
    *(int*)(THD_TS_ADDR+344)=ROTHD_THREAD43_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD45_VALID
    *(int*)(THD_TS_ADDR+360)=ROTHD_THREAD45_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD46_VALID
    *(int*)(THD_TS_ADDR+368)=ROTHD_THREAD46_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD47_VALID
    *(int*)(THD_TS_ADDR+376)=ROTHD_THREAD47_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD49_VALID
    *(int*)(THD_TS_ADDR+392)=ROTHD_THREAD49_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD50_VALID
    *(int*)(THD_TS_ADDR+400)=ROTHD_THREAD50_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD51_VALID
    *(int*)(THD_TS_ADDR+408)=ROTHD_THREAD51_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD53_VALID
    *(int*)(THD_TS_ADDR+424)=ROTHD_THREAD53_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD54_VALID
    *(int*)(THD_TS_ADDR+432)=ROTHD_THREAD54_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD55_VALID
    *(int*)(THD_TS_ADDR+440)=ROTHD_THREAD55_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD57_VALID
    *(int*)(THD_TS_ADDR+456)=ROTHD_THREAD57_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD58_VALID
    *(int*)(THD_TS_ADDR+464)=ROTHD_THREAD58_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD59_VALID
    *(int*)(THD_TS_ADDR+472)=ROTHD_THREAD59_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD61_VALID
    *(int*)(THD_TS_ADDR+488)=ROTHD_THREAD61_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD62_VALID
    *(int*)(THD_TS_ADDR+496)=ROTHD_THREAD62_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD63_VALID
    *(int*)(THD_TS_ADDR+504)=ROTHD_THREAD63_FREQCFG_VALUE;
#endif



#ifdef ROTHD_THREAD4_VALID
    *(int*)(THD_TS_ADDR+32)=ROTHD_THREAD4_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD8_VALID
    *(int*)(THD_TS_ADDR+64)=ROTHD_THREAD8_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD12_VALID
    *(int*)(THD_TS_ADDR+96)=ROTHD_THREAD12_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD16_VALID
    *(int*)(THD_TS_ADDR+128)=ROTHD_THREAD16_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD20_VALID
    *(int*)(THD_TS_ADDR+160)=ROTHD_THREAD20_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD24_VALID
    *(int*)(THD_TS_ADDR+192)=ROTHD_THREAD24_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD28_VALID
    *(int*)(THD_TS_ADDR+224)=ROTHD_THREAD28_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD32_VALID
    *(int*)(THD_TS_ADDR+256)=ROTHD_THREAD32_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD36_VALID
    *(int*)(THD_TS_ADDR+288)=ROTHD_THREAD36_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD40_VALID
    *(int*)(THD_TS_ADDR+320)=ROTHD_THREAD40_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD44_VALID
    *(int*)(THD_TS_ADDR+352)=ROTHD_THREAD44_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD48_VALID
    *(int*)(THD_TS_ADDR+384)=ROTHD_THREAD48_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD52_VALID
    *(int*)(THD_TS_ADDR+416)=ROTHD_THREAD52_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD56_VALID
    *(int*)(THD_TS_ADDR+448)=ROTHD_THREAD56_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD60_VALID
    *(int*)(THD_TS_ADDR+480)=ROTHD_THREAD60_FREQCFG_VALUE;
#endif

#ifdef ROTHD_THREAD0_VALID
    *(int*)(THD_TS_ADDR+0)=ROTHD_THREAD0_FREQCFG_VALUE;
    rothd_set_sp_const(ROTHD_THREAD0_STACKCFG_VALUE|0x20000000);
#endif


#ifdef ROTHD_THREAD0_VALID
extern void thread0_main();
    thread0_main();
#endif

}


void (*thread_initial_pointer[64]) (void)={
                                               &thread0_initial,
                                               &thread1_initial,
                                               &thread2_initial,
                                               &thread3_initial,
                                               &thread4_initial,
                                               &thread5_initial,
                                               &thread6_initial,
                                               &thread7_initial,
                                               &thread8_initial,
                                               &thread9_initial,
                                               &thread10_initial,
                                               &thread11_initial,
                                               &thread12_initial,
                                               &thread13_initial,
                                               &thread14_initial,
                                               &thread15_initial,
                                               &thread16_initial,
                                               &thread17_initial,
                                               &thread18_initial,
                                               &thread19_initial,
                                               &thread20_initial,
                                               &thread21_initial,
                                               &thread22_initial,
                                               &thread23_initial,
                                               &thread24_initial,
                                               &thread25_initial,
                                               &thread26_initial,
                                               &thread27_initial,
                                               &thread28_initial,
                                               &thread29_initial,
                                               &thread30_initial,
                                               &thread31_initial,
                                               &thread32_initial,
                                               &thread33_initial,
                                               &thread34_initial,
                                               &thread35_initial,
                                               &thread36_initial,
                                               &thread37_initial,
                                               &thread38_initial,
                                               &thread39_initial,
                                               &thread40_initial,
                                               &thread41_initial,
                                               &thread42_initial,
                                               &thread43_initial,
                                               &thread44_initial,
                                               &thread45_initial,
                                               &thread46_initial,
                                               &thread47_initial,
                                               &thread48_initial,
                                               &thread49_initial,
                                               &thread50_initial,
                                               &thread51_initial,
                                               &thread52_initial,
                                               &thread53_initial,
                                               &thread54_initial,
                                               &thread55_initial,
                                               &thread56_initial,
                                               &thread57_initial,
                                               &thread58_initial,
                                               &thread59_initial,
                                               &thread60_initial,
                                               &thread61_initial,
                                               &thread62_initial,
                                               &thread63_initial
};


void thread_start(void)
{
    (*thread_initial_pointer[THREAD_ID])();
}


#endif



