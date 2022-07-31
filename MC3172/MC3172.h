
/*--------------------------------------------------------------------------
MC3172.H V1.01
****************************************
**  Copyright  (C)    2021-2022   **
**  Web:              http://rothd.cn   **
****************************************
--------------------------------------------------------------------------*/

/*----- constant and type define -----------------------------------------*/
#ifndef MC3172_H
#define MC3172_H

#ifndef TRUE
#define TRUE    1
#define FALSE   0
#endif
#ifndef NULL
#define NULL    0
#endif



#ifndef u8
typedef unsigned char                   u8;
#endif
#ifndef u16
typedef unsigned short                  u16;
#endif
#ifndef u32
typedef unsigned long                   u32;
#endif
#ifndef i8
typedef char                            i8;
#endif
#ifndef i16
typedef short                           i16;
#endif
#ifndef i32
typedef long                            i32;
#endif

#ifndef UINT8
typedef unsigned char                   UINT8;
#endif
#ifndef UINT16
typedef unsigned short                  UINT16;
#endif
#ifndef UINT32
typedef unsigned long                   UINT32;
#endif

//  Set Stack Pointer
#define rothd_set_sp_const(value)               rothd_set_sp_const1(value)
#define rothd_set_sp_const1(value)              asm volatile ("li   sp,"#value"")

#define rothd_set_sp_int(value)                 asm volatile ("mv   %0,sp" : : "r" (value))
#define rothd_get_sp(result)                    asm volatile ("mv   sp,%0" : "=r" (result))

#define NOP()              asm volatile ("nop")



#define THREAD_ID_ADDR                          0x50000000
#define CORE_CNT_ADDR                           0x50000008
#define CORE_INFO1_ADDR                         0x50000400

#define GET_CORE_CNT(var)                       var=(*(volatile u32*)(CORE_CNT_ADDR))
#define GET_THREAD_ID(var)                      var=(*(volatile u8*)(THREAD_ID_ADDR))

#define CORE_CNT                                (*(volatile u32*)(CORE_CNT_ADDR))

#define THD_TS_ADDR                             0x50020000

#define THREAD_ID                               (*(volatile u8*)(0x50000000))
#define DATA_RAM_RATIO                          (*(volatile u8*)(0x50010000))

#define CORE_CLK_CFG_ADDR                       0x50050108


#define INTDEV_RESET                            0x00000
#define INTDEV_RUN                              0x10000

#define INTDEV_CLK_IS_STOP                      0x0000
#define INTDEV_CLK_IS_CORECLK                   0x0001
#define INTDEV_CLK_IS_CORECLK_DIV2              0x0002
#define INTDEV_CLK_IS_CORECLK_DIV4              0x0003
#define INTDEV_CLK_IS_CORECLK_DIV8              0x0004
#define INTDEV_CLK_IS_CORECLK_DIV16             0x0005
#define INTDEV_CLK_IS_CORECLK_DIV32             0x0006
#define INTDEV_CLK_IS_CORECLK_DIV64             0x0007
#define INTDEV_CLK_IS_CORECLK_DIV128            0x0008
#define INTDEV_CLK_IS_CORECLK_DIV256            0x0009
#define INTDEV_CLK_IS_CORECLK_DIV512            0x000a
#define INTDEV_CLK_IS_CORECLK_DIV1024           0x000b
#define INTDEV_CLK_IS_CORECLK_DIV2048           0x000c
#define INTDEV_CLK_IS_CORECLK_DIV4096           0x000d
#define INTDEV_CLK_IS_CORECLK_DIV8192           0x000e
#define INTDEV_CLK_IS_CORECLK_DIV16384          0x000f

#define INTDEV_IS_GROUP0                        0x0000
#define INTDEV_IS_GROUP1                        0x0100
#define INTDEV_IS_GROUP2                        0x0200
#define INTDEV_IS_GROUP3                        0x0300







#define INTDEV_SET_CLK_RST(DEV_ADDR,value)      (*(volatile u32*)(DEV_ADDR))=(value)

////////////////////////////////////////////////////////////

#define WDG_EN_ADDR                             0x50040108
#define WDG_RELOAD_VALUE_ADDR                   0x50040118
#define WDG_RESET_CFG_ADDR                      0x50040120
#define WDG_RENEW_ADDR                          0x50040128


////////////////////////////////////////////////////////////





#define RCS_RCOSC_ADJ_SET4_ADDR                 0x50050088;
#define RCS_RCOSC_ADJ_SET5_ADDR                 0x50050090;
#define RCS_RCOSC_ADJ_SET6_ADDR                 0x50050098;
#define RCS_RCOSC_ADJ_SET0_ADDR                 0x500500a0;
#define RCS_RCOSC_ADJ_SET1_ADDR                 0x500500a8;
#define RCS_RCOSC_ADJ_SET2_ADDR                 0x500500b0;
#define RCS_RCOSC_ADJ_SET3_ADDR                 0x500500b8;
#define RCS_RCOSC_ADJ_STATUS1_ADDR              0x500500b8;
#define RCS_RCOSC_ADJ_STATUS2_ADDR              0x500500b8;




////////////////////////////////////////////////////////////

#define GPIO0_BASE_ADDR                         0x60100000
#define GPIO1_BASE_ADDR                         0x60101000
#define GPIO2_BASE_ADDR                         0x60102000
#define GPIO3_BASE_ADDR                         0x60103000

#define GPIOA_BASE_ADDR                         0x60100000
#define GPIOB_BASE_ADDR                         0x60101000
#define GPIOC_BASE_ADDR                         0x60102000
#define GPIOD_BASE_ADDR                         0x60103000



#define GPIO_OUT_VALUE_ADDR                     0x0100
#define GPIO_OUT_SET1_ADDR                      0x0108
#define GPIO_OUT_SET0_ADDR                      0x0110
#define GPIO_OUT_INV_ADDR                       0x0118

#define GPIO_SET_OUTPUT_PIN_VALUE(GPIO_SEL,mask,value)      (*(volatile u32*)(GPIO_SEL+GPIO_OUT_VALUE_ADDR))=(value|mask)
#define GPIO_SET_OUTPUT_PIN_TO_1(GPIO_SEL,value)            (*(volatile u32*)(GPIO_SEL+GPIO_OUT_SET1_ADDR)) =(value&0xffff0000)
#define GPIO_SET_OUTPUT_PIN_TO_0(GPIO_SEL,value)            (*(volatile u32*)(GPIO_SEL+GPIO_OUT_SET0_ADDR)) =(value&0xffff0000)
#define GPIO_SET_OUTPUT_PIN_INV(GPIO_SEL,value)             (*(volatile u32*)(GPIO_SEL+GPIO_OUT_INV_ADDR))  =(value&0xffff0000)


#define GPIO_OUTPUT_EN_ADDR                     0x0140
#define GPIO_INPUT_EN_ADDR                      0x0c0
#define GPIO_DRIVE_MODE_ADDR                    0x168
#define GPIO_PULL_UP_ADDR                       0x170
#define GPIO_PULL_DOWN_ADDR                     0x178

#define GPIO_SET_INPUT_EN_VALUE(GPIO_SEL,mask,value)    (*(volatile u32*)(GPIO_SEL+GPIO_INPUT_EN_ADDR))=(value|mask)
#define GPIO_SET_OUTPUT_EN_VALUE(GPIO_SEL,mask,value)   (*(volatile u32*)(GPIO_SEL+GPIO_OUTPUT_EN_ADDR))=(value|mask)

#define GPIO_SET_DRIVE_MODE_VALUE(GPIO_SEL,mask,value)  (*(volatile u32*)(GPIO_SEL+GPIO_DRIVE_MODE_ADDR))=(value|mask)
#define GPIO_SET_PULL_UP_VALUE(GPIO_SEL,mask,value)     (*(volatile u32*)(GPIO_SEL+GPIO_PULL_UP_ADDR))=(value|mask)

#define GPIO_READ_REAL_OVERRIDE_ADDR            0x040
#define GPIO_READ_REAL_INOUT_EN_ADDR            0x048
#define GPIO_READ_REAL_DRIVE_MODE_ADDR          0x050
#define GPIO_READ_REAL_PULL_MODE_ADDR           0x058


#define GPIO_GET_OVERRIDE_VALUE(GPIO_SEL)       (*(volatile u32*)(GPIO_SEL+GPIO_READ_REAL_OVERRIDE_ADDR))
#define GPIO_GET_INPUT_EN_VALUE(GPIO_SEL)       (*(volatile u16*)(GPIO_SEL+GPIO_READ_REAL_INOUT_EN_ADDR))
#define GPIO_GET_OUTPUT_EN_VALUE(GPIO_SEL)      (*(volatile u16*)(GPIO_SEL+GPIO_READ_REAL_INOUT_EN_ADDR+2))
#define GPIO_GET_DRIVE_MODE_VALUE(GPIO_SEL)     (*(volatile u16*)(GPIO_SEL+GPIO_READ_REAL_DRIVE_MODE_ADDR))
#define GPIO_GET_PULL_UP_VALUE(GPIO_SEL)        (*(volatile u16*)(GPIO_SEL+GPIO_READ_REAL_PULL_MODE_ADDR+2))
#define GPIO_GET_PULL_DOWN_VALUE(GPIO_SEL)      (*(volatile u16*)(GPIO_SEL+GPIO_READ_REAL_PULL_MODE_ADDR))




//#define GPIO_READ_CFG_PULL_DOWN_ADDR 0x080
//#define GPIO_READ_CFG_PULL_UP_ADDR 0x088
//#define GPIO_READ_CFG_DRIVE_MODE_ADDR 0x090
//#define GPIO_READ_CFG_INPUT_EN_ADDR 0x098
//
//#define GPIO_READ_CFG_OUTPUT_VALUE_ADDR 0x100
//#define GPIO_READ_CFG_OUTPUT_EN_ADDR 0x110



#define GPIO_READ_REAL_INPUT_VALUE_ADDR 0x180
#define GPIO_READ_SAFE_INPUT_VALUE_ADDR 0x190
#define GPIO_GET_INPUT_VALUE_SAFE(GPIO_SEL)     (*(volatile u16*)(GPIO_SEL+GPIO_READ_SAFE_INPUT_VALUE_ADDR))
#define GPIO_GET_INPUT_VALUE_FAST(GPIO_SEL)     (*(volatile u16*)(GPIO_SEL+GPIO_READ_REAL_INOUT_EN_ADDR))





#define GPIO_PIN0                               0x00010000
#define GPIO_PIN1                               0x00020000
#define GPIO_PIN2                               0x00040000
#define GPIO_PIN3                               0x00080000
#define GPIO_PIN4                               0x00100000
#define GPIO_PIN5                               0x00200000
#define GPIO_PIN6                               0x00400000
#define GPIO_PIN7                               0x00800000
#define GPIO_PIN8                               0x01000000
#define GPIO_PIN9                               0x02000000
#define GPIO_PIN10                              0x04000000
#define GPIO_PIN11                              0x08000000
#define GPIO_PIN12                              0x10000000
#define GPIO_PIN13                              0x20000000
#define GPIO_PIN14                              0x40000000
#define GPIO_PIN15                              0x80000000

#define GPIO_PIN_ALL                            0xffff0000
#define GPIO_PIN_7_0                            0x00ff0000
#define GPIO_PIN_15_8                           0xff000000



#define GPIO_SET_ENABLE                         0xffff
#define GPIO_SET_DISABLE                        0x0000





////////////////////////////////////////////////////////////




#define TIMER0_BASE_ADDR                        0x60200000
#define TIMER1_BASE_ADDR                        0x60201000
#define TIMER2_BASE_ADDR                        0x60202000
#define TIMER3_BASE_ADDR                        0x60203000
#define TIMER4_BASE_ADDR                        0x60204000
#define TIMER5_BASE_ADDR                        0x60205000


#define TIMER_CMD_ADDR                          0x00000008
#define TIMER_OVERRIDE_GPIO_ADDR                0x00000010
#define TIMER_OUT_MODE_ADDR                     0x00000020
#define TIMER_OE_ADDR                           0x00000028
#define TIMER_IN_MODE_ADDR                      0x00000030
#define TIMER_CAPTURER_MODE_ADDR                0x00000040
#define TIMER_COMPARER_MODE_ADDR                0x00000048
#define TIMER_READ_CAPTURER_MODE_ADDR           0x00000048
#define TIMER_READ_COMPARER_MODE_ADDR           0x00000040

#define TIMER_MAIN_CNT_BEGIN_VALUE0_ADDR        0x000000c0
#define TIMER_MAIN_CNT_END_VALUE0_ADDR          0x000000c8
#define TIMER_MAIN_CNT_BEGIN_VALUE1_ADDR        0x000000d0
#define TIMER_MAIN_CNT_END_VALUE1_ADDR          0x000000d8





#define CAPTURER0_VALUE_WP_ADDR                 0x0f8
#define CAPTURER1_VALUE_WP_ADDR                 0x0f9
#define CAPTURER2_VALUE_WP_ADDR                 0x0fa
#define CAPTURER3_VALUE_WP_ADDR                 0x0fb


#define CAPTURER0_VALUE0_ADDR                   0x00000100
#define CAPTURER0_VALUE1_ADDR                   0x00000108

#define CAPTURER1_VALUE0_ADDR                   0x00000120
#define CAPTURER1_VALUE1_ADDR                   0x00000128

#define CAPTURER2_VALUE0_ADDR                   0x00000140
#define CAPTURER2_VALUE1_ADDR                   0x00000148

#define CAPTURER3_VALUE0_ADDR                   0x00000160
#define CAPTURER3_VALUE1_ADDR                   0x00000168





#define TIMER_COMPARER0_VALUE0_ADDR               0x0200
#define TIMER_COMPARER0_VALUE1_ADDR               0x0208
#define TIMER_COMPARER0_VALUE2_ADDR               0x0210
#define TIMER_COMPARER0_VALUE3_ADDR               0x0218

#define TIMER_COMPARER1_VALUE0_ADDR               0x0280
#define TIMER_COMPARER1_VALUE1_ADDR               0x0288
#define TIMER_COMPARER1_VALUE2_ADDR               0x0290
#define TIMER_COMPARER1_VALUE3_ADDR               0x0298

#define TIMER_COMPARER2_VALUE0_ADDR               0x0300
#define TIMER_COMPARER2_VALUE1_ADDR               0x0308
#define TIMER_COMPARER2_VALUE2_ADDR               0x0310
#define TIMER_COMPARER2_VALUE3_ADDR               0x0318

#define TIMER_COMPARER3_VALUE0_ADDR               0x0380
#define TIMER_COMPARER3_VALUE1_ADDR               0x0388
#define TIMER_COMPARER3_VALUE2_ADDR               0x0390
#define TIMER_COMPARER3_VALUE3_ADDR               0x0398




#define TIMER_SET_OVERRIDE_GPIO(TIMER_SEL,value)            (*(volatile u32*)(TIMER_SEL+TIMER_OVERRIDE_GPIO_ADDR)) = value
#define TIMER_SET_OUT_PORT(TIMER_SEL,value)                 (*(volatile u32*)(TIMER_SEL+TIMER_OUT_MODE_ADDR)) = value
#define TIMER_SET_OUTPUT_EN(TIMER_SEL,value)                (*(volatile u32*)(TIMER_SEL+TIMER_OE_ADDR)) = value
#define TIMER_SET_IN_PORT(TIMER_SEL,value)                  (*(volatile u32*)(TIMER_SEL+TIMER_IN_MODE_ADDR)) = value
#define TIMER_SET_CAPTURER_MODE(TIMER_SEL,value)            (*(volatile u32*)(TIMER_SEL+TIMER_CAPTURER_MODE_ADDR)) = value
#define TIMER_SET_COMPARER_MODE(TIMER_SEL,value)            (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER_MODE_ADDR)) = value


#define TIMER_MAIN_CNT_COUNT_UP                   0x80000000
#define TIMER_MAIN_CNT_COUNT_DOWN                 0x7fffffff

#define TIMER_SET_MAIN_CNT_BEGIN_VALUE0(TIMER_SEL,value1,value2)                \
                        if(value1==TIMER_MAIN_CNT_COUNT_UP) \
                        (*(volatile u32*)(TIMER_SEL+TIMER_MAIN_CNT_BEGIN_VALUE0_ADDR)) = (TIMER_MAIN_CNT_COUNT_UP|value2); \
                        else (*(volatile u32*)(TIMER_SEL+TIMER_MAIN_CNT_BEGIN_VALUE0_ADDR)) = (TIMER_MAIN_CNT_COUNT_DOWN&value2)

#define TIMER_SET_MAIN_CNT_END_VALUE0(TIMER_SEL,value)                  (*(volatile u32*)(TIMER_SEL+TIMER_MAIN_CNT_END_VALUE0_ADDR)) = (value)

#define TIMER_SET_MAIN_CNT_BEGIN_VALUE1(TIMER_SEL,value1,value2)                \
                        if(value1==TIMER_MAIN_CNT_COUNT_UP) \
                        (*(volatile u32*)(TIMER_SEL+TIMER_MAIN_CNT_BEGIN_VALUE1_ADDR)) = (TIMER_MAIN_CNT_COUNT_UP|value2); \
                        else (*(volatile u32*)(TIMER_SEL+TIMER_MAIN_CNT_BEGIN_VALUE1_ADDR)) = (TIMER_MAIN_CNT_COUNT_DOWN&value2)

#define TIMER_SET_MAIN_CNT_END_VALUE1(TIMER_SEL,value)                  (*(volatile u32*)(TIMER_SEL+TIMER_MAIN_CNT_END_VALUE1_ADDR)) = value

#define TIMER_SET_CMD(TIMER_SEL,value)                                  (*(volatile u32*)(TIMER_SEL+TIMER_CMD_ADDR)) = value


#define TIMER_GET_MAIN_CNT_ALL(TIMER_SEL,main_cnt,main_cnt_rp)          main_cnt = (*(volatile u32*)(TIMER_SEL+0x12*8));\
                                                                        main_cnt_rp = main_cnt>>24;\
                                                                        main_cnt = main_cnt&0x00ffffff

#define TIMER_GET_MAIN_CNT_RP(TIMER_SEL,main_cnt_rp)                    main_cnt_rp = (*(volatile u8*)(TIMER_SEL+0x11*8))
#define TIMER_GET_MAIN_CNT(TIMER_SEL,main_cnt)                          main_cnt = (*(volatile u32*)(TIMER_SEL+0x10*8))






#define TIMER0_CAPTURE0_WP                   (*(volatile u8*)(TIMER0_BASE_ADDR+CAPTURER0_VALUE_WP_ADDR))
#define TIMER0_CAPTURE1_WP                   (*(volatile u8*)(TIMER0_BASE_ADDR+CAPTURER1_VALUE_WP_ADDR))
#define TIMER0_CAPTURE2_WP                   (*(volatile u8*)(TIMER0_BASE_ADDR+CAPTURER2_VALUE_WP_ADDR))
#define TIMER0_CAPTURE3_WP                   (*(volatile u8*)(TIMER0_BASE_ADDR+CAPTURER3_VALUE_WP_ADDR))

#define TIMER1_CAPTURE0_WP                   (*(volatile u8*)(TIMER1_BASE_ADDR+CAPTURER0_VALUE_WP_ADDR))
#define TIMER1_CAPTURE1_WP                   (*(volatile u8*)(TIMER1_BASE_ADDR+CAPTURER1_VALUE_WP_ADDR))
#define TIMER1_CAPTURE2_WP                   (*(volatile u8*)(TIMER1_BASE_ADDR+CAPTURER2_VALUE_WP_ADDR))
#define TIMER1_CAPTURE3_WP                   (*(volatile u8*)(TIMER1_BASE_ADDR+CAPTURER3_VALUE_WP_ADDR))

#define TIMER2_CAPTURE0_WP                   (*(volatile u8*)(TIMER2_BASE_ADDR+CAPTURER0_VALUE_WP_ADDR))
#define TIMER2_CAPTURE1_WP                   (*(volatile u8*)(TIMER2_BASE_ADDR+CAPTURER1_VALUE_WP_ADDR))
#define TIMER2_CAPTURE2_WP                   (*(volatile u8*)(TIMER2_BASE_ADDR+CAPTURER2_VALUE_WP_ADDR))
#define TIMER2_CAPTURE3_WP                   (*(volatile u8*)(TIMER2_BASE_ADDR+CAPTURER3_VALUE_WP_ADDR))

#define TIMER3_CAPTURE0_WP                   (*(volatile u8*)(TIMER3_BASE_ADDR+CAPTURER0_VALUE_WP_ADDR))
#define TIMER3_CAPTURE1_WP                   (*(volatile u8*)(TIMER3_BASE_ADDR+CAPTURER1_VALUE_WP_ADDR))
#define TIMER3_CAPTURE2_WP                   (*(volatile u8*)(TIMER3_BASE_ADDR+CAPTURER2_VALUE_WP_ADDR))
#define TIMER3_CAPTURE3_WP                   (*(volatile u8*)(TIMER3_BASE_ADDR+CAPTURER3_VALUE_WP_ADDR))

#define TIMER4_CAPTURE0_WP                   (*(volatile u8*)(TIMER4_BASE_ADDR+CAPTURER0_VALUE_WP_ADDR))
#define TIMER4_CAPTURE1_WP                   (*(volatile u8*)(TIMER4_BASE_ADDR+CAPTURER1_VALUE_WP_ADDR))
#define TIMER4_CAPTURE2_WP                   (*(volatile u8*)(TIMER4_BASE_ADDR+CAPTURER2_VALUE_WP_ADDR))
#define TIMER4_CAPTURE3_WP                   (*(volatile u8*)(TIMER4_BASE_ADDR+CAPTURER3_VALUE_WP_ADDR))

#define TIMER5_CAPTURE0_WP                   (*(volatile u8*)(TIMER5_BASE_ADDR+CAPTURER0_VALUE_WP_ADDR))
#define TIMER5_CAPTURE1_WP                   (*(volatile u8*)(TIMER5_BASE_ADDR+CAPTURER1_VALUE_WP_ADDR))
#define TIMER5_CAPTURE2_WP                   (*(volatile u8*)(TIMER5_BASE_ADDR+CAPTURER2_VALUE_WP_ADDR))
#define TIMER5_CAPTURE3_WP                   (*(volatile u8*)(TIMER5_BASE_ADDR+CAPTURER3_VALUE_WP_ADDR))





#define TIMER_GET_CAPTURE0_WP(TIMER_SEL)                                (*(volatile u8*)(TIMER_SEL+CAPTURER0_VALUE_WP_ADDR))
#define TIMER_GET_CAPTURE1_WP(TIMER_SEL)                                (*(volatile u8*)(TIMER_SEL+CAPTURER1_VALUE_WP_ADDR))
#define TIMER_GET_CAPTURE2_WP(TIMER_SEL)                                (*(volatile u8*)(TIMER_SEL+CAPTURER2_VALUE_WP_ADDR))
#define TIMER_GET_CAPTURE3_WP(TIMER_SEL)                                (*(volatile u8*)(TIMER_SEL+CAPTURER3_VALUE_WP_ADDR))

#define TIMER_GET_CAPTURE0_VALUE(TIMER_SEL,rp)                      (*(volatile u32*)(TIMER_SEL+CAPTURER0_VALUE0_ADDR+((rp&0x1)*8)))
#define TIMER_GET_CAPTURE1_VALUE(TIMER_SEL,rp)                      (*(volatile u32*)(TIMER_SEL+CAPTURER1_VALUE0_ADDR+((rp&0x1)*8)))
#define TIMER_GET_CAPTURE2_VALUE(TIMER_SEL,rp)                      (*(volatile u32*)(TIMER_SEL+CAPTURER2_VALUE0_ADDR+((rp&0x1)*8)))
#define TIMER_GET_CAPTURE3_VALUE(TIMER_SEL,rp)                      (*(volatile u32*)(TIMER_SEL+CAPTURER3_VALUE0_ADDR+((rp&0x1)*8)))



#define TIMER_SET_COMPARER0_VALUE0_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER0_VALUE0_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER0_VALUE0_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER0_VALUE1_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER0_VALUE1_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER0_VALUE2_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER0_VALUE1_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER0_VALUE3_ADDR)) = value1|(value2&0xffffff)

#define TIMER_SET_COMPARER1_VALUE0_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER1_VALUE0_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER1_VALUE0_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER1_VALUE1_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER1_VALUE1_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER1_VALUE2_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER1_VALUE1_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER1_VALUE3_ADDR)) = value1|(value2&0xffffff)

#define TIMER_SET_COMPARER2_VALUE0_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER2_VALUE0_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER2_VALUE0_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER2_VALUE1_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER2_VALUE1_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER2_VALUE2_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER2_VALUE1_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER2_VALUE3_ADDR)) = value1|(value2&0xffffff)

#define TIMER_SET_COMPARER3_VALUE0_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER3_VALUE0_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER3_VALUE0_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER3_VALUE1_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER3_VALUE1_0(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER3_VALUE2_ADDR)) = value1|(value2&0xffffff)
#define TIMER_SET_COMPARER3_VALUE1_1(TIMER_SEL,value1,value2)                 (*(volatile u32*)(TIMER_SEL+TIMER_COMPARER3_VALUE3_ADDR)) = value1|(value2&0xffffff)


#define TIMER_CMD_RUN                           0x10000001
#define TIMER_CMD_RESTART                       0x20000001
#define TIMER_CMD_HOLD                          0x00000001

#define TIMER_P7_OVERRIDE_GPIO                  0x10000000
#define TIMER_P7_INPUT_ENABLE                   0x20000000
#define TIMER_P7_PULL_UP                        0x80000000

#define TIMER_P6_OVERRIDE_GPIO                  0x01000000
#define TIMER_P6_INPUT_ENABLE                   0x02000000
#define TIMER_P6_PULL_UP                        0x08000000

#define TIMER_P5_OVERRIDE_GPIO                  0x00100000
#define TIMER_P5_INPUT_ENABLE                   0x00200000
#define TIMER_P5_PULL_UP                        0x00800000

#define TIMER_P4_OVERRIDE_GPIO                  0x00010000
#define TIMER_P4_INPUT_ENABLE                   0x00020000
#define TIMER_P4_PULL_UP                        0x00080000

#define TIMER_P3_OVERRIDE_GPIO                  0x00001000
#define TIMER_P3_INPUT_ENABLE                   0x00002000
#define TIMER_P3_PULL_UP                        0x00008000

#define TIMER_P2_OVERRIDE_GPIO                  0x00000100
#define TIMER_P2_INPUT_ENABLE                   0x00000200
#define TIMER_P2_PULL_UP                        0x00000800

#define TIMER_P1_OVERRIDE_GPIO                  0x00000010
#define TIMER_P1_INPUT_ENABLE                   0x00000020
#define TIMER_P1_PULL_UP                        0x00000080

#define TIMER_P0_OVERRIDE_GPIO                  0x00000001
#define TIMER_P0_INPUT_ENABLE                   0x00000002
#define TIMER_P0_PULL_UP                        0x00000008

#define TIMER_P0_OUTPUT_ENABLE                  0x0000000c
#define TIMER_P1_OUTPUT_ENABLE                  0x000000c0
#define TIMER_P2_OUTPUT_ENABLE                  0x00000c00
#define TIMER_P3_OUTPUT_ENABLE                  0x0000c000

#define TIMER_P4_OUTPUT_ENABLE                  0x000c0000
#define TIMER_P5_OUTPUT_ENABLE                  0x00c00000
#define TIMER_P6_OUTPUT_ENABLE                  0x0c000000
#define TIMER_P7_OUTPUT_ENABLE                  0xc0000000

#define TIMER_P0_OUTPUT_DISABLE                 0x00000004
#define TIMER_P1_OUTPUT_DISABLE                 0x00000040
#define TIMER_P2_OUTPUT_DISABLE                 0x00000400
#define TIMER_P3_OUTPUT_DISABLE                 0x00004000

#define TIMER_P4_OUTPUT_DISABLE                 0x00040000
#define TIMER_P5_OUTPUT_DISABLE                 0x00400000
#define TIMER_P6_OUTPUT_DISABLE                 0x04000000
#define TIMER_P7_OUTPUT_DISABLE                 0x40000000


#define TIMER_COMPARER0_FORCE0                  0x00000000
#define TIMER_COMPARER0_FORCE1                  0x00010000
#define TIMER_COMPARER0_NOT_FORCE               0x00020000

#define TIMER_COMPARER1_FORCE0                  0x00000000
#define TIMER_COMPARER1_FORCE1                  0x00100000
#define TIMER_COMPARER1_NOT_FORCE               0x00200000

#define TIMER_COMPARER2_FORCE0                  0x00000000
#define TIMER_COMPARER2_FORCE1                  0x01000000
#define TIMER_COMPARER2_NOT_FORCE               0x02000000

#define TIMER_COMPARER3_FORCE0                  0x00000000
#define TIMER_COMPARER3_FORCE1                  0x10000000
#define TIMER_COMPARER3_NOT_FORCE               0x20000000




#define TIMER_COMPARER_HOLD                     0x00000000
#define TIMER_COMPARER_INV                      0x10000000
#define TIMER_COMPARER_OUTPUT0                  0x20000000
#define TIMER_COMPARER_OUTPUT1                  0x30000000


#define TIMER_CAPTURER0_FILTER_ENABLE           0x00040000
#define TIMER_CAPTURER0_RISING_EDGE             0x00020000
#define TIMER_CAPTURER0_FALLING_EDGE            0x00010000

#define TIMER_CAPTURER1_FILTER_ENABLE           0x00400000
#define TIMER_CAPTURER1_RISING_EDGE             0x00200000
#define TIMER_CAPTURER1_FALLING_EDGE            0x00100000

#define TIMER_CAPTURER2_FILTER_ENABLE           0x04000000
#define TIMER_CAPTURER2_RISING_EDGE             0x02000000
#define TIMER_CAPTURER2_FALLING_EDGE            0x01000000

#define TIMER_CAPTURER3_FILTER_ENABLE           0x40000000
#define TIMER_CAPTURER3_RISING_EDGE             0x20000000
#define TIMER_CAPTURER3_FALLING_EDGE            0x10000000







#define TIMER_P0_IS_COMPARER0    0x00000000
#define TIMER_P0_IS_COMPARER1    0x00000001
#define TIMER_P0_IS_COMPARER2    0x00000002
#define TIMER_P0_IS_COMPARER3    0x00000003
#define TIMER_P0_IS_LOW          0x00000004
#define TIMER_P0_IS_TIMER_CLK    0x00000005
#define TIMER_P0_IS_HIGH         0x0000000c

#define TIMER_P1_IS_COMPARER0    0x00000000
#define TIMER_P1_IS_COMPARER1    0x00000010
#define TIMER_P1_IS_COMPARER2    0x00000020
#define TIMER_P1_IS_COMPARER3    0x00000030
#define TIMER_P1_IS_LOW          0x00000040
#define TIMER_P1_IS_TIMER_CLK    0x00000050
#define TIMER_P1_IS_HIGH         0x000000c0

#define TIMER_P2_IS_COMPARER0    0x00000000
#define TIMER_P2_IS_COMPARER1    0x00000100
#define TIMER_P2_IS_COMPARER2    0x00000200
#define TIMER_P2_IS_COMPARER3    0x00000300
#define TIMER_P2_IS_LOW          0x00000400
#define TIMER_P2_IS_TIMER_CLK    0x00000500
#define TIMER_P2_IS_HIGH         0x00000c00

#define TIMER_P3_IS_COMPARER0    0x00000000
#define TIMER_P3_IS_COMPARER1    0x00001000
#define TIMER_P3_IS_COMPARER2    0x00002000
#define TIMER_P3_IS_COMPARER3    0x00003000
#define TIMER_P3_IS_LOW          0x00004000
#define TIMER_P3_IS_TIMER_CLK    0x00005000
#define TIMER_P3_IS_HIGH         0x0000c000

#define TIMER_P4_IS_COMPARER0    0x00000000
#define TIMER_P4_IS_COMPARER1    0x00010000
#define TIMER_P4_IS_COMPARER2    0x00020000
#define TIMER_P4_IS_COMPARER3    0x00030000
#define TIMER_P4_IS_LOW          0x00040000
#define TIMER_P4_IS_TIMER_CLK    0x00050000
#define TIMER_P4_IS_HIGH         0x000c0000

#define TIMER_P5_IS_COMPARER0    0x00000000
#define TIMER_P5_IS_COMPARER1    0x00100000
#define TIMER_P5_IS_COMPARER2    0x00200000
#define TIMER_P5_IS_COMPARER3    0x00300000
#define TIMER_P5_IS_LOW          0x00400000
#define TIMER_P5_IS_TIMER_CLK    0x00500000
#define TIMER_P5_IS_HIGH         0x00c00000

#define TIMER_P6_IS_COMPARER0    0x00000000
#define TIMER_P6_IS_COMPARER1    0x01000000
#define TIMER_P6_IS_COMPARER2    0x02000000
#define TIMER_P6_IS_COMPARER3    0x03000000
#define TIMER_P6_IS_LOW          0x04000000
#define TIMER_P6_IS_TIMER_CLK    0x05000000
#define TIMER_P6_IS_HIGH         0x0c000000

#define TIMER_P7_IS_COMPARER0    0x00000000
#define TIMER_P7_IS_COMPARER1    0x10000000
#define TIMER_P7_IS_COMPARER2    0x20000000
#define TIMER_P7_IS_COMPARER3    0x30000000
#define TIMER_P7_IS_LOW          0x40000000
#define TIMER_P7_IS_TIMER_CLK    0x50000000
#define TIMER_P7_IS_HIGH         0xc0000000



#define TIMER_CAPTURER0_IS_P0    0x00000000
#define TIMER_CAPTURER0_IS_P1    0x00000001
#define TIMER_CAPTURER0_IS_P2    0x00000002
#define TIMER_CAPTURER0_IS_P3    0x00000003
#define TIMER_CAPTURER0_IS_P4    0x00000004
#define TIMER_CAPTURER0_IS_P5    0x00000005
#define TIMER_CAPTURER0_IS_P6    0x00000006
#define TIMER_CAPTURER0_IS_P7    0x00000007


#define TIMER_CAPTURER1_IS_P0    0x00000000
#define TIMER_CAPTURER1_IS_P1    0x00000008
#define TIMER_CAPTURER1_IS_P2    0x00000010
#define TIMER_CAPTURER1_IS_P3    0x00000018
#define TIMER_CAPTURER1_IS_P4    0x00000020
#define TIMER_CAPTURER1_IS_P5    0x00000028
#define TIMER_CAPTURER1_IS_P6    0x00000030
#define TIMER_CAPTURER1_IS_P7    0x00000038



#define TIMER_CAPTURER2_IS_P0    0x00000000
#define TIMER_CAPTURER2_IS_P1    0x00000040
#define TIMER_CAPTURER2_IS_P2    0x00000080
#define TIMER_CAPTURER2_IS_P3    0x000000c0
#define TIMER_CAPTURER2_IS_P4    0x00000100
#define TIMER_CAPTURER2_IS_P5    0x00000140
#define TIMER_CAPTURER2_IS_P6    0x00000180
#define TIMER_CAPTURER2_IS_P7    0x000001c0


#define TIMER_CAPTURER3_IS_P0    0x00000000
#define TIMER_CAPTURER3_IS_P1    0x00000200
#define TIMER_CAPTURER3_IS_P2    0x00000400
#define TIMER_CAPTURER3_IS_P3    0x00000600
#define TIMER_CAPTURER3_IS_P4    0x00000800
#define TIMER_CAPTURER3_IS_P5    0x00000a00
#define TIMER_CAPTURER3_IS_P6    0x00000c00
#define TIMER_CAPTURER3_IS_P7    0x00000e00



#define TIMER_CAPTURER3_RISING_EDGE      0x20000000
#define TIMER_CAPTURER3_FALLING_EDGE     0x10000000







////////////////////////////////////////////////////////////



#define GPCOM0_BASE_ADDR                    0x60300000
#define GPCOM1_BASE_ADDR                    0x60301000
#define GPCOM2_BASE_ADDR                    0x60302000
#define GPCOM3_BASE_ADDR                    0x60303000
#define GPCOM4_BASE_ADDR                    0x60304000
#define GPCOM5_BASE_ADDR                    0x60305000
#define GPCOM6_BASE_ADDR                    0x60306000
#define GPCOM7_BASE_ADDR                    0x60307000
#define GPCOM8_BASE_ADDR                    0x60308000
#define GPCOM9_BASE_ADDR                    0x60309000
#define GPCOM10_BASE_ADDR                   0x6030a000
#define GPCOM11_BASE_ADDR                   0x6030b000

#define GPCOM_ITEM1_ADDR                    0x00000008
#define GPCOM_ITEM2_ADDR                    0x00000010
#define GPCOM_ITEM3_ADDR                    0x00000018
#define GPCOM_ITEM4_ADDR                    0x00000020

#define GPCOM_OVERRIDE_GPIO_ADDR            0x00000040
#define GPCOM_IN_MODE_ADDR                  0x00000048
#define GPCOM_OUT_MODE_ADDR                 0x00000060


#define GPCOM_TX_DATA_WP_ADDR               0x00000078
#define GPCOM_TX_DATA_RP_ADDR               0x00000079
#define GPCOM_TX_DATA_STATE_ADDR            0x0000007a
#define GPCOM_TX_DATA_BUF0_WPINC_ADDR       0x00000100
#define GPCOM_TX_DATA_BUF1_WPINC_ADDR       0x00000108
#define GPCOM_TX_DATA_BUF2_WPINC_ADDR       0x00000110
#define GPCOM_TX_DATA_BUF3_WPINC_ADDR       0x00000118
#define GPCOM_TX_DATA_BUF4_WPINC_ADDR       0x00000120
#define GPCOM_TX_DATA_BUF5_WPINC_ADDR       0x00000128
#define GPCOM_TX_DATA_BUF6_WPINC_ADDR       0x00000130
#define GPCOM_TX_DATA_BUF7_WPINC_ADDR       0x00000138
#define GPCOM_TX_DATA_BUF0_ADDR             0x00000180
#define GPCOM_TX_DATA_BUF1_ADDR             0x00000188
#define GPCOM_TX_DATA_BUF2_ADDR             0x00000190
#define GPCOM_TX_DATA_BUF3_ADDR             0x00000198
#define GPCOM_TX_DATA_BUF4_ADDR             0x000001a0
#define GPCOM_TX_DATA_BUF5_ADDR             0x000001a8
#define GPCOM_TX_DATA_BUF6_ADDR             0x000001b0
#define GPCOM_TX_DATA_BUF7_ADDR             0x000001b8
#define GPCOM_TX_DATA_BUF_3_0_WPINC_ADDR    0x000000c0
#define GPCOM_TX_DATA_BUF_7_4_WPINC_ADDR    0x000000c8
#define GPCOM_TX_DATA_BUF_3_0_ADDR          0x000000e0
#define GPCOM_TX_DATA_BUF_7_4_ADDR          0x000000e8

#define GPCOM_RX_DATA_WP_ADDR               0x00000250
#define GPCOM_RX_DATA_BUF0_ADDR             0x00000380
#define GPCOM_RX_DATA_BUF1_ADDR             0x00000388
#define GPCOM_RX_DATA_BUF2_ADDR             0x00000390
#define GPCOM_RX_DATA_BUF3_ADDR             0x00000398
#define GPCOM_RX_DATA_BUF4_ADDR             0x000003a0
#define GPCOM_RX_DATA_BUF5_ADDR             0x000003a8
#define GPCOM_RX_DATA_BUF6_ADDR             0x000003b0
#define GPCOM_RX_DATA_BUF7_ADDR             0x000003b8
#define GPCOM_RX_DATA_BUF_3_0_ADDR          0x000002e0
#define GPCOM_RX_DATA_BUF_7_4_ADDR          0x000002e8


#define GPCOM_SET_OVERRIDE_GPIO(GPCOM_SEL,value)            (*(volatile u32*)(GPCOM_SEL+GPCOM_OVERRIDE_GPIO_ADDR)) = value

#define GPCOM_SET_OUT_PORT(GPCOM_SEL,value)                 (*(volatile u32*)(GPCOM_SEL+GPCOM_OUT_MODE_ADDR)) = value
#define GPCOM_SET_IN_PORT(GPCOM_SEL,value)                  (*(volatile u32*)(GPCOM_SEL+GPCOM_IN_MODE_ADDR)) = value

#define GPCOM_SET_COM_MODE(GPCOM_SEL,value)                 (*(volatile u32*)(GPCOM_SEL+GPCOM_ITEM1_ADDR)) = value
#define GPCOM_SET_COM_SPEED(GPCOM_SEL,clk_speed,baudrate)   (*(volatile u32*)(GPCOM_SEL+GPCOM_ITEM2_ADDR)) = (((clk_speed/baudrate)-1)<<8)+(clk_speed/baudrate)/2-2
#define GPCOM_SET_COM_DETIAL1(GPCOM_SEL,value)              (*(volatile u32*)(GPCOM_SEL+GPCOM_ITEM3_ADDR)) = value
#define GPCOM_SET_COM_DETIAL2(GPCOM_SEL,value)              (*(volatile u32*)(GPCOM_SEL+GPCOM_ITEM4_ADDR)) = value

#define GPCOM_SEND_TX_DATA(GPCOM_SEL,wp,value)              (*(volatile u32*)(GPCOM_SEL+GPCOM_TX_DATA_BUF0_ADDR+((wp&0x7)*8))) = value
#define GPCOM_SEND_TX_DATA_WPINC(GPCOM_SEL,wp,value)        (*(volatile u32*)(GPCOM_SEL+GPCOM_TX_DATA_BUF0_WPINC_ADDR+((wp&0x7)*8))) = value

#define GPCOM_PUSH_TX_DATA(GPCOM_SEL,value)                 (*(volatile u32*)(GPCOM_SEL+GPCOM_TX_DATA_BUF0_WPINC_ADDR+ (( (*(volatile u32*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR))*8 )&0x3f) )) = value


#define GPCOM_SEND_TX_WP(GPCOM_SEL,value)                   (*(volatile u32*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR)) = value
#define GPCOM_GET_TX_WP(GPCOM_SEL)                          (*(volatile u32*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR))

#define GPCOM_GET_RX_DATA(GPCOM_SEL,rp)                     (*(volatile u32*)(GPCOM_SEL+GPCOM_RX_DATA_BUF0_ADDR+(((rp&0x7)*8))))
#define GPCOM_GET_RX_WP(GPCOM_SEL)                          (*(volatile u8*)(GPCOM_SEL+GPCOM_RX_DATA_WP_ADDR))




#define GPCOM0_TX_WP                    (*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM0_TX_RP                    (*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM0_TX_STATE                 (*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM0_RX_WP                    (*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM1_TX_WP                    (*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM1_TX_RP                    (*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM1_TX_STATE                 (*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM1_RX_WP                    (*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM2_TX_WP                    (*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM2_TX_RP                    (*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM2_TX_STATE                 (*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM2_RX_WP                    (*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM3_TX_WP                    (*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM3_TX_RP                    (*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM3_TX_STATE                 (*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM3_RX_WP                    (*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM4_TX_WP                    (*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM4_TX_RP                    (*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM4_TX_STATE                 (*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM4_RX_WP                    (*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM5_TX_WP                    (*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM5_TX_RP                    (*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM5_TX_STATE                 (*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM5_RX_WP                    (*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM6_TX_WP                    (*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM6_TX_RP                    (*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM6_TX_STATE                 (*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM6_RX_WP                    (*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM7_TX_WP                    (*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM7_TX_RP                    (*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM7_TX_STATE                 (*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM7_RX_WP                    (*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM8_TX_WP                    (*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM8_TX_RP                    (*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM8_TX_STATE                 (*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM8_RX_WP                    (*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM9_TX_WP                    (*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM9_TX_RP                    (*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM9_TX_STATE                 (*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM9_RX_WP                    (*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM10_TX_WP                   (*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM10_TX_RP                   (*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM10_TX_STATE                (*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM10_RX_WP                   (*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))

#define GPCOM11_TX_WP                   (*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR))
#define GPCOM11_TX_RP                   (*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))
#define GPCOM11_TX_STATE                (*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_STATE_ADDR))
#define GPCOM11_RX_WP                   (*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_RX_DATA_WP_ADDR))


#define GPCOM_TX_FIFO_FULL(GPCOM_SEL)             (((*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM_TX_FIFO_EMPTY(GPCOM_SEL)            (((*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR)))


#define GPCOM0_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM0_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM0_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM1_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM1_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM1_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM2_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM2_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM2_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM3_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM3_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM3_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM4_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM4_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM4_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM5_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM5_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM5_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM6_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM6_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM6_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM7_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM7_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM7_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM8_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM8_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM8_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM9_TX_FIFO_FULL             (((*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM9_TX_FIFO_EMPTY            (((*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM9_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM10_TX_FIFO_FULL            (((*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM10_TX_FIFO_EMPTY           (((*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM10_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))

#define GPCOM11_TX_FIFO_FULL            (((*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM11_TX_FIFO_EMPTY           (((*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM11_BASE_ADDR+GPCOM_TX_DATA_WP_ADDR)))


#define GPCOM_TX_FIFO_FULL(GPCOM_SEL)            (((*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_RP_ADDR))^0x8)==(*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR)))
#define GPCOM_TX_FIFO_EMPTY(GPCOM_SEL)           (((*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_RP_ADDR)))    ==(*(volatile u8*)(GPCOM_SEL+GPCOM_TX_DATA_WP_ADDR)))



#define GPCOM_UART_MODE                 0x00000001

#define GPCOM_SPI_MASTER_MODE0          0x00000003
#define GPCOM_SPI_MASTER_MODE1          0x00000023
#define GPCOM_SPI_MASTER_MODE2          0x00000013
#define GPCOM_SPI_MASTER_MODE3          0x00000033

#define GPCOM_SPI_SLAVE_MODE0           0x00000103
#define GPCOM_SPI_SLAVE_MODE1           0x00000123
#define GPCOM_SPI_SLAVE_MODE2           0x00000113
#define GPCOM_SPI_SLAVE_MODE3           0x00000133

#define GPCOM_TX_MSB_FIRST              0x00000080
#define GPCOM_TX_LSB_FIRST              0x00000000
#define GPCOM_RX_MSB_FIRST              0x00000040
#define GPCOM_RX_LSB_FIRST              0x00000000

#define GPCOM_P0_IS_TXD                 0x00000000
#define GPCOM_P0_IS_MASTER_OUT          0x00000000
#define GPCOM_P0_IS_SLAVE_OUT           0x00000002
#define GPCOM_P0_IS_MASTER_CLK          0x00000001
#define GPCOM_P0_IS_DP                  0x00000000
#define GPCOM_P0_IS_DM                  0x00000001
#define GPCOM_P0_IS_HIGH                0x00000007
#define GPCOM_P0_IS_LOW                 0x00000003

#define GPCOM_P1_IS_TXD                 0x00000000
#define GPCOM_P1_IS_MASTER_OUT          0x00000000
#define GPCOM_P1_IS_SLAVE_OUT           0x00000020
#define GPCOM_P1_IS_MASTER_CLK          0x00000010
#define GPCOM_P1_IS_DP                  0x00000000
#define GPCOM_P1_IS_DM                  0x00000010
#define GPCOM_P1_IS_HIGH                0x00000070
#define GPCOM_P1_IS_LOW                 0x00000030

#define GPCOM_P2_IS_TXD                 0x00000000
#define GPCOM_P2_IS_MASTER_OUT          0x00000000
#define GPCOM_P2_IS_SLAVE_OUT           0x00000200
#define GPCOM_P2_IS_MASTER_CLK          0x00000100
#define GPCOM_P2_IS_DP                  0x00000000
#define GPCOM_P2_IS_DM                  0x00000100
#define GPCOM_P2_IS_HIGH                0x00000700
#define GPCOM_P2_IS_LOW                 0x00000300

#define GPCOM_P3_IS_TXD                 0x00000000
#define GPCOM_P3_IS_MASTER_OUT          0x00000000
#define GPCOM_P3_IS_SLAVE_OUT           0x00002000
#define GPCOM_P3_IS_MASTER_CLK          0x00001000
#define GPCOM_P3_IS_DP                  0x00000000
#define GPCOM_P3_IS_DM                  0x00001000
#define GPCOM_P3_IS_HIGH                0x00007000
#define GPCOM_P3_IS_LOW                 0x00003000


#define GPCOM_RXD_IS_P0                 0x00000000
#define GPCOM_RXD_IS_P1                 0x00000001
#define GPCOM_RXD_IS_P2                 0x00000002
#define GPCOM_RXD_IS_P3                 0x00000003

#define GPCOM_MASTER_IN_IS_P0           0x00000000
#define GPCOM_MASTER_IN_IS_P1           0x00000001
#define GPCOM_MASTER_IN_IS_P2           0x00000002
#define GPCOM_MASTER_IN_IS_P3           0x00000003

#define GPCOM_SLAVE_IN_IS_P0            0x00000000
#define GPCOM_SLAVE_IN_IS_P1            0x00000001
#define GPCOM_SLAVE_IN_IS_P2            0x00000002
#define GPCOM_SLAVE_IN_IS_P3            0x00000003

#define GPCOM_SLAVE_CLK_IS_P0           0x00000000
#define GPCOM_SLAVE_CLK_IS_P1           0x00000008
#define GPCOM_SLAVE_CLK_IS_P2           0x00000010
#define GPCOM_SLAVE_CLK_IS_P3           0x00000018

#define GPCOM_SLAVE_CS_IS_P0            0x00000000
#define GPCOM_SLAVE_CS_IS_P1            0x00000400
#define GPCOM_SLAVE_CS_IS_P2            0x00000800
#define GPCOM_SLAVE_CS_IS_P3            0x00000c00


#define GPCOM_DP_IS_P0                  0x00000000
#define GPCOM_DP_IS_P1                  0x00000001
#define GPCOM_DP_IS_P2                  0x00000002
#define GPCOM_DP_IS_P3                  0x00000003

#define GPCOM_DM_IS_P0                  0x00000000
#define GPCOM_DM_IS_P1                  0x00000008
#define GPCOM_DM_IS_P2                  0x00000010
#define GPCOM_DM_IS_P3                  0x00000018

#define GPCOM_P3_OVERRIDE_GPIO          0x01000000
#define GPCOM_P3_INPUT_ENABLE           0x02000000
#define GPCOM_P3_PULL_UP                0x08000000

#define GPCOM_P2_OVERRIDE_GPIO          0x00010000
#define GPCOM_P2_INPUT_ENABLE           0x00020000
#define GPCOM_P2_PULL_UP                0x00080000

#define GPCOM_P1_OVERRIDE_GPIO          0x00000100
#define GPCOM_P1_INPUT_ENABLE           0x00000200
#define GPCOM_P1_PULL_UP                0x00000800

#define GPCOM_P0_OVERRIDE_GPIO          0x00000001
#define GPCOM_P0_INPUT_ENABLE           0x00000002
#define GPCOM_P0_PULL_UP                0x00000008


#define GPCOM_P0_OUTPUT_ENABLE          0x00070000
#define GPCOM_P1_OUTPUT_ENABLE          0x00700000
#define GPCOM_P2_OUTPUT_ENABLE          0x07000000
#define GPCOM_P3_OUTPUT_ENABLE          0x70000000

#define GPCOM_P0_OUTPUT_DISABLE         0x00030000
#define GPCOM_P1_OUTPUT_DISABLE         0x00300000
#define GPCOM_P2_OUTPUT_DISABLE         0x03000000
#define GPCOM_P3_OUTPUT_DISABLE         0x30000000





////////////////////////////////////////////////////////////



#endif  // MC3172_H
