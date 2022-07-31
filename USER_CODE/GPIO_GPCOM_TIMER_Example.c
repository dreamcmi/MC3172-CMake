/*--------------------------------------------------------------------------
Example.c
****************************************
**  Copyright  (C)    2021-2022   **
**  Web:              http://rothd.cn   **
****************************************
--------------------------------------------------------------------------*/

#include "MC3172.h"
#include "GPIO_GPCOM_TIMER_Example.h"
////////////////////////////////////////////////////////////

void GPIO_EXAMPLE(u32 gpio_sel)
{
    INTDEV_SET_CLK_RST(gpio_sel,(INTDEV_RUN|INTDEV_IS_GROUP0|INTDEV_CLK_IS_CORECLK_DIV2));

    GPIO_SET_OUTPUT_EN_VALUE(gpio_sel,(GPIO_PIN_7_0),GPIO_SET_ENABLE);
    GPIO_SET_INPUT_EN_VALUE(gpio_sel,(GPIO_PIN_15_8),GPIO_SET_ENABLE);

    GPIO_SET_OUTPUT_PIN_TO_1(gpio_sel,(GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3));
    GPIO_SET_OUTPUT_PIN_TO_0(gpio_sel,(GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7));

    while(1)  {

        GPIO_SET_OUTPUT_PIN_INV(gpio_sel,(GPIO_PIN0|GPIO_PIN2));
        u16 rx_data;
        rx_data=GPIO_GET_INPUT_VALUE_SAFE(gpio_sel);
        GPIO_SET_OUTPUT_PIN_VALUE(gpio_sel,(GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7),(rx_data>>4));

        for (u32 var = 0; var < 5000; ++var) {
            NOP();
        }
    }

}

////////////////////////////////////////////////////////////


void GPCOM_UART_EXAMPLE(u32 gpcom_sel)
{
    INTDEV_SET_CLK_RST(gpcom_sel,(INTDEV_RUN|INTDEV_IS_GROUP0|INTDEV_CLK_IS_CORECLK_DIV4));

    GPCOM_SET_IN_PORT(gpcom_sel,(GPCOM_RXD_IS_P2));
    GPCOM_SET_OUT_PORT(gpcom_sel,( \
            GPCOM_P0_OUTPUT_DISABLE|GPCOM_P3_OUTPUT_ENABLE|GPCOM_P2_OUTPUT_DISABLE|GPCOM_P1_OUTPUT_DISABLE| \
            GPCOM_P0_IS_HIGH       |GPCOM_P3_IS_TXD       |GPCOM_P2_IS_HIGH       |GPCOM_P1_IS_HIGH \
                      ));

    GPCOM_SET_COM_MODE(gpcom_sel,GPCOM_UART_MODE);

    GPCOM_SET_COM_SPEED(gpcom_sel,12000000,115200);

    GPCOM_SET_OVERRIDE_GPIO(gpcom_sel, ( \
            GPCOM_P2_OVERRIDE_GPIO|GPCOM_P2_INPUT_ENABLE | \
            GPCOM_P3_OVERRIDE_GPIO \
                                              ));
#ifdef TEST_ONLY_UART_TX
    while(1){
        while(GPCOM_TX_FIFO_FULL(gpcom_sel));
        for (u32 var = 0; var < 90; ++var) {
            NOP();
        }
        GPCOM_PUSH_TX_DATA(gpcom_sel,0x31);
    }

#else
    u8 rx_data_rp=0;
    u8 rx_data=0;
    rx_data_rp=GPCOM_GET_RX_WP(gpcom_sel);
    while(1) {
         if(rx_data_rp!=(GPCOM_GET_RX_WP(gpcom_sel))){
              rx_data=GPCOM_GET_RX_DATA(gpcom_sel,rx_data_rp);
              GPCOM_PUSH_TX_DATA(gpcom_sel,rx_data);
              rx_data_rp++;
              rx_data_rp&=0x0f;
         }
    }
#endif
}


void GPCOM_SPI_EXAMPLE(u32 gpcom_sel)
{
    volatile u8 rx_data_temp[8];

    INTDEV_SET_CLK_RST(gpcom_sel,(INTDEV_RUN|INTDEV_IS_GROUP0|INTDEV_CLK_IS_CORECLK_DIV2));

    GPCOM_SET_IN_PORT(gpcom_sel,(GPCOM_MASTER_IN_IS_P3));
    GPCOM_SET_OUT_PORT(gpcom_sel,( \
            GPCOM_P0_OUTPUT_ENABLE|GPCOM_P1_OUTPUT_ENABLE|GPCOM_P2_OUTPUT_ENABLE|GPCOM_P3_OUTPUT_DISABLE| \
            GPCOM_P0_IS_HIGH|      GPCOM_P1_IS_MASTER_CLK|GPCOM_P2_IS_MASTER_OUT|GPCOM_P3_IS_HIGH
                      ));

    GPCOM_SET_COM_MODE(gpcom_sel,(GPCOM_SPI_MASTER_MODE3|GPCOM_TX_MSB_FIRST|GPCOM_RX_MSB_FIRST));

    GPCOM_SET_COM_SPEED(gpcom_sel,24000000,1000000);

    GPCOM_SET_OVERRIDE_GPIO(gpcom_sel, ( \
            GPCOM_P0_OVERRIDE_GPIO| \
            GPCOM_P1_OVERRIDE_GPIO| \
            GPCOM_P2_OVERRIDE_GPIO| \
            GPCOM_P3_OVERRIDE_GPIO|GPCOM_P3_INPUT_ENABLE  \
                                              ));




    u8 tx_data_wp=0;
    u8 rx_data_rp=0;
    tx_data_wp=GPCOM_GET_TX_WP(gpcom_sel);
    rx_data_rp=GPCOM_GET_RX_WP(gpcom_sel);

    while(1){

        GPCOM_SET_OUT_PORT(gpcom_sel,( \
                GPCOM_P0_OUTPUT_ENABLE|GPCOM_P1_OUTPUT_ENABLE|GPCOM_P2_OUTPUT_ENABLE|GPCOM_P3_OUTPUT_DISABLE| \
                GPCOM_P0_IS_LOW|      GPCOM_P1_IS_MASTER_CLK| GPCOM_P2_IS_MASTER_OUT|GPCOM_P3_IS_HIGH
                          ));

        GPCOM_SEND_TX_DATA(gpcom_sel,tx_data_wp+0,CORE_CNT);
        GPCOM_SEND_TX_DATA(gpcom_sel,tx_data_wp+1,CORE_CNT);
        GPCOM_SEND_TX_DATA(gpcom_sel,tx_data_wp+2,CORE_CNT);
        GPCOM_SEND_TX_DATA(gpcom_sel,tx_data_wp+3,CORE_CNT);

        tx_data_wp+=4;
        GPCOM_SEND_TX_WP(gpcom_sel,tx_data_wp);
        while(!(GPCOM_TX_FIFO_EMPTY(gpcom_sel))){};




        while(rx_data_rp!=GPCOM_GET_RX_WP(gpcom_sel)){
            rx_data_temp[rx_data_rp&0x7]=GPCOM_GET_RX_DATA(gpcom_sel,rx_data_rp);
            rx_data_rp+=1;
            rx_data_rp&=0xf;

        };

        GPCOM_SET_OUT_PORT(gpcom_sel,( \
                GPCOM_P0_OUTPUT_ENABLE|GPCOM_P1_OUTPUT_ENABLE|GPCOM_P2_OUTPUT_ENABLE|GPCOM_P3_OUTPUT_DISABLE| \
                GPCOM_P0_IS_HIGH|      GPCOM_P1_IS_MASTER_CLK| GPCOM_P2_IS_MASTER_OUT|GPCOM_P3_IS_HIGH
                          ));
    }

}


void TIMER_COMPARER_EXAMPLE(u32 timer_sel)
{


    INTDEV_SET_CLK_RST(timer_sel,(INTDEV_RUN|INTDEV_IS_GROUP0|INTDEV_CLK_IS_CORECLK));


    TIMER_SET_OVERRIDE_GPIO(timer_sel,(
                                       TIMER_P3_OVERRIDE_GPIO|TIMER_P3_PULL_UP| \
                                       TIMER_P2_OVERRIDE_GPIO| \
                                       TIMER_P1_OVERRIDE_GPIO| \
                                       TIMER_P0_OVERRIDE_GPIO) \
                           );



    TIMER_SET_OUTPUT_EN(timer_sel,(TIMER_P0_OUTPUT_ENABLE |TIMER_P1_OUTPUT_ENABLE |TIMER_P2_OUTPUT_ENABLE |TIMER_P3_OUTPUT_ENABLE| \
                                   TIMER_P4_OUTPUT_DISABLE|TIMER_P5_OUTPUT_DISABLE|TIMER_P6_OUTPUT_DISABLE|TIMER_P7_OUTPUT_DISABLE));


    TIMER_SET_OUT_PORT(timer_sel,(TIMER_P0_IS_COMPARER0|TIMER_P1_IS_COMPARER1|TIMER_P3_IS_COMPARER2|TIMER_P2_IS_COMPARER3));

    TIMER_SET_COMPARER_MODE(timer_sel,(TIMER_COMPARER3_NOT_FORCE|TIMER_COMPARER2_NOT_FORCE|TIMER_COMPARER1_NOT_FORCE|TIMER_COMPARER0_NOT_FORCE));

    TIMER_SET_MAIN_CNT_BEGIN_VALUE0(timer_sel,TIMER_MAIN_CNT_COUNT_UP,0x00000000);
    TIMER_SET_MAIN_CNT_END_VALUE0(timer_sel,0x1000);
    TIMER_SET_MAIN_CNT_BEGIN_VALUE1(timer_sel,TIMER_MAIN_CNT_COUNT_DOWN,0x00008000);
    TIMER_SET_MAIN_CNT_END_VALUE1(timer_sel,0x00007000);
    TIMER_SET_CMD(timer_sel,TIMER_CMD_RESTART);



    TIMER_SET_COMPARER0_VALUE0_0(timer_sel,TIMER_COMPARER_OUTPUT0,0xf2);
    TIMER_SET_COMPARER0_VALUE0_1(timer_sel,TIMER_COMPARER_OUTPUT1,0x1f2);
    TIMER_SET_COMPARER0_VALUE1_0(timer_sel,TIMER_COMPARER_OUTPUT0,0x7777);
    TIMER_SET_COMPARER0_VALUE1_1(timer_sel,TIMER_COMPARER_OUTPUT1,0x7666);

    TIMER_SET_COMPARER1_VALUE0_0(timer_sel,TIMER_COMPARER_INV,0x1e4);
    TIMER_SET_COMPARER1_VALUE0_1(timer_sel,TIMER_COMPARER_HOLD,0x553);
    TIMER_SET_COMPARER1_VALUE1_0(timer_sel,TIMER_COMPARER_INV,0x7291);
    TIMER_SET_COMPARER1_VALUE1_1(timer_sel,TIMER_COMPARER_HOLD,0x327);

    TIMER_SET_COMPARER2_VALUE0_0(timer_sel,TIMER_COMPARER_OUTPUT0,0x202);
    TIMER_SET_COMPARER2_VALUE0_1(timer_sel,TIMER_COMPARER_INV,0x303);
    TIMER_SET_COMPARER2_VALUE1_0(timer_sel,TIMER_COMPARER_OUTPUT0,0x189);
    TIMER_SET_COMPARER2_VALUE1_1(timer_sel,TIMER_COMPARER_INV,0x377);

    TIMER_SET_COMPARER3_VALUE0_0(timer_sel,TIMER_COMPARER_OUTPUT0,0xf12);
    TIMER_SET_COMPARER3_VALUE0_1(timer_sel,TIMER_COMPARER_OUTPUT1,0x733);
    TIMER_SET_COMPARER3_VALUE1_0(timer_sel,TIMER_COMPARER_INV,0x7569);
    TIMER_SET_COMPARER3_VALUE1_1(timer_sel,TIMER_COMPARER_INV,0x7227);

    TIMER_SET_CMD(timer_sel,TIMER_CMD_RUN);
    while(1);
}


void TIMER_CAPTURER_EXAMPLE(u32 timer_sel)
{



    INTDEV_SET_CLK_RST(timer_sel,(INTDEV_RUN|INTDEV_IS_GROUP0|INTDEV_CLK_IS_CORECLK));


    TIMER_SET_OUTPUT_EN(timer_sel,(TIMER_P0_OUTPUT_ENABLE|TIMER_P1_OUTPUT_ENABLE|TIMER_P2_OUTPUT_ENABLE|TIMER_P3_OUTPUT_ENABLE| \
                                   TIMER_P4_OUTPUT_DISABLE|TIMER_P5_OUTPUT_DISABLE|TIMER_P6_OUTPUT_DISABLE|TIMER_P7_OUTPUT_DISABLE));


    TIMER_SET_IN_PORT(timer_sel,(TIMER_CAPTURER0_IS_P7|TIMER_CAPTURER1_IS_P5|TIMER_CAPTURER2_IS_P6|TIMER_CAPTURER3_IS_P4));
    //TIMER_SET_OUT_PORT(timer_sel,(TIMER_P0_IS_COMPARER0|TIMER_P1_IS_COMPARER1|TIMER_P3_IS_COMPARER2|TIMER_P2_IS_COMPARER3));


    TIMER_SET_OVERRIDE_GPIO(timer_sel,(TIMER_P7_OVERRIDE_GPIO|TIMER_P7_INPUT_ENABLE|TIMER_P7_PULL_UP| \
                                       TIMER_P6_OVERRIDE_GPIO|TIMER_P6_INPUT_ENABLE| \
                                       TIMER_P5_OVERRIDE_GPIO|TIMER_P5_INPUT_ENABLE| \
                                       TIMER_P4_OVERRIDE_GPIO|TIMER_P4_INPUT_ENABLE \
                                      )
                            );



    //TIMER_SET_COMPARER_MODE(timer_sel,(TIMER_COMPARER3_NOT_FORCE|TIMER_COMPARER2_NOT_FORCE|TIMER_COMPARER1_NOT_FORCE|TIMER_COMPARER0_NOT_FORCE));

    TIMER_SET_MAIN_CNT_BEGIN_VALUE0(timer_sel,TIMER_MAIN_CNT_COUNT_UP,0x00000000);
    TIMER_SET_MAIN_CNT_END_VALUE0(timer_sel,0x00100000);
    TIMER_SET_MAIN_CNT_BEGIN_VALUE1(timer_sel,TIMER_MAIN_CNT_COUNT_UP,0x00e00000);
    TIMER_SET_MAIN_CNT_END_VALUE1(timer_sel,0x00f00000);
    TIMER_SET_CMD(timer_sel,TIMER_CMD_RESTART);


    TIMER_SET_CAPTURER_MODE(timer_sel,(TIMER_CAPTURER0_FILTER_ENABLE|TIMER_CAPTURER0_RISING_EDGE|TIMER_CAPTURER0_FALLING_EDGE|TIMER_CAPTURER1_RISING_EDGE|TIMER_CAPTURER3_FALLING_EDGE));




    u8 capturer0_data_rp=0;
    u8 capturer1_data_rp=0;
    u8 capturer2_data_rp=0;
    u8 capturer3_data_rp=0;

    capturer0_data_rp=TIMER_GET_CAPTURE0_WP(timer_sel);
    capturer1_data_rp=TIMER_GET_CAPTURE1_WP(timer_sel);
    capturer2_data_rp=TIMER_GET_CAPTURE2_WP(timer_sel);
    capturer3_data_rp=TIMER_GET_CAPTURE3_WP(timer_sel);


    volatile u32 capturer0_data_temp[8];
    volatile u32 capturer1_data_temp[8];
    volatile u32 capturer2_data_temp[8];
    volatile u32 capturer3_data_temp[8];

    TIMER_SET_CMD(timer_sel,TIMER_CMD_RUN);

    while(1){
        if((capturer0_data_rp&0x1)!=TIMER_GET_CAPTURE0_WP(timer_sel)){
            capturer0_data_temp[capturer0_data_rp]=TIMER_GET_CAPTURE0_VALUE(timer_sel,capturer0_data_rp);
            capturer0_data_rp++;
            capturer0_data_rp&=0x7;
        }
        if((capturer1_data_rp&0x1)!=TIMER_GET_CAPTURE1_WP(timer_sel)){
            capturer1_data_temp[capturer1_data_rp]=TIMER_GET_CAPTURE1_VALUE(timer_sel,capturer1_data_rp);
            capturer1_data_rp++;
            capturer1_data_rp&=0x7;
        }
        if((capturer2_data_rp&0x1)!=TIMER_GET_CAPTURE2_WP(timer_sel)){
            capturer2_data_temp[capturer2_data_rp]=TIMER_GET_CAPTURE2_VALUE(timer_sel,capturer2_data_rp);
            capturer2_data_rp++;
            capturer2_data_rp&=0x7;
        }
        if((capturer3_data_rp&0x1)!=TIMER_GET_CAPTURE3_WP(timer_sel)){
            capturer3_data_temp[capturer3_data_rp]=TIMER_GET_CAPTURE3_VALUE(timer_sel,capturer3_data_rp);
            capturer3_data_rp++;
            capturer3_data_rp&=0x7;
        }
    }



}

////////////////////////////////////////////////////////////



