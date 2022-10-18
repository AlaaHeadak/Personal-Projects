/*
 * RCC_Interface.h
 *
 *  Created on: Oct 18, 2022
 *      Author: LENOVO
 */

#ifndef ARM_MCAL_RCC_RCC_INTERFACE_H_
#define ARM_MCAL_RCC_RCC_INTERFACE_H_
#include "../../general_configuration.h"


#define RCC_AHB1    0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2    3






//(RCC_AHB1ENR)
#define RCC_GPIOAEN  0
#define RCC_GPIOBEN  1
#define RCC_GPIOCEN  2
#define RCC_GPIODEN  3
#define RCC_GPIOEEN  4
#define RCC_GPIOHEN  7
#define RCC_CRCEN  12
#define RCC_DMA1EN  21
#define RCC_DMA2EN  22

//(RCC_AHB2ENR)
#define RCC_OTGFSEN  7

//(RCC_APB1ENR)
#define RCC_TIM2EN  0
#define RCC_TIM3EN  1
#define RCC_TIM4EN  2
#define RCC_TIM5EN  3
#define RCC_WWDGEN  11
#define RCC_SPI2EN  14
#define RCC_SPI3EN  15
#define RCC_USART2EN  17
#define RCC_I2C1EN  21
#define RCC_I2C2EN  22
#define RCC_I2C3EN  23
#define RCC_PWREN  28

//(RCC_APB2ENR)
#define RCC_TIM1EN  0
#define RCC_USART1EN  4
#define RCC_USART6EN  5
#define RCC_ADC1EN  8
#define RCC_SDIOEN  11
#define RCC_SPI1EN  12
#define RCC_SPI4EN  13
#define RCC_SYSCFGEN  14
#define RCC_TIM9EN  16
#define RCC_TIM10EN  17
#define RCC_TIM11EN  18


/* RCC PLLCFGR  Configuration */
#define RCC_PLL_P_MASK 0xFFFCFFFF
#define RCC_PLL_P_INDEX 16
#define RCC_PLLCFGR_PLLP_MHZ	RCC_PLLP_MHZ_CFG

#define RCC_PLL_N_MASK 0xFFFF803F
#define RCC_PLL_N_INDEX 6
#define RCC_PLLCFGR_PLLN_MHZ	RCC_PLLN_MHZ_CFG

#define RCC_PLL_M_MASK 0x3FFFFFE0
#define RCC_PLL_M_INDEX 0
#define RCC_PLLCFGR_PLLM_MHZ	RCC_PLLM_MHZ_CFG

															// 0xFF &
#define RCC_PLLCFGR_PLL_P()	((RCC->PLLCFGR & RCC_PLL_P_MASK) | ((RCC_PLLCFGR_PLLP_MHZ << RCC_PLL_P_INDEX)))

#define RCC_PLLCFGR_PLLN_MHZ    RCC_PLLN_MHZ_CFG
#define RCC_PLLCFGR_PLL_N()	((RCC->PLLCFGR & RCC_PLL_N_MASK) | ((RCC_PLLCFGR_PLLN_MHZ << RCC_PLL_N_INDEX)))

#define RCC_PLLCFGR_PLLM_MHZ    RCC_PLLM_MHZ_CFG
#define RCC_PLLCFGR_PLL_M()	((RCC->PLLCFGR & RCC_PLL_M_MASK) | ((RCC_PLLCFGR_PLLM_MHZ << RCC_PLL_M_INDEX)))

void MRCC_vInit(void);
//enable the clock
void MRCC_vEnableClock();
//disable the clock
void MRCC_vDisableClock();




#endif /* ARM_MCAL_RCC_RCC_INTERFACE_H_ */
