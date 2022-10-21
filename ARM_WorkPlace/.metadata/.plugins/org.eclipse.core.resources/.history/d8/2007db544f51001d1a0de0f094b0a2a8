/*
 * RCC_Configuration.h
 *
 *  Created on: Oct 18, 2022
 *      Author: LENOVO
 */

#ifndef ARM_MCAL_RCC_RCC_CONFIGURATION_H_
#define ARM_MCAL_RCC_RCC_CONFIGURATION_H_


#define RCC_HSE_ENABLE  ENABLE
#define RCC_HSi_ENABLE  DISABLE
#define RCC_PLL_ENABLE  DISABLE

#define RCC_CSS_ENABLE  ENABLE

#if  RCC_SYS_CLK_RCC
	#define RCC_SYS_CLK  RCC
	#define RCC_PLL_BASIC_CLOCK_INPUT_MHZ 32 // 32.768
#elif RCC_SYS_CLK_HSE
	#define RCC_SYS_CLK  HSE
	#define RCC_PLL_BASIC_CLOCK_INPUT_MHZ 8
#elif RCC_SYS_CLK_HSI
	#define RCC_SYS_CLK  HSI
	#define RCC_PLL_BASIC_CLOCK_INPUT_MHZ 16
#endif

#define VCO 1  /* choose either 1 or 2 */




#endif /* ARM_MCAL_RCC_RCC_CONFIGURATION_H_ */
