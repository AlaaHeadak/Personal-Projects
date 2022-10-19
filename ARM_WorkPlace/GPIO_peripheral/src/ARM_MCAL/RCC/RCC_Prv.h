/*
 * RCC_Prv.h
 *
 *  Created on: Oct 18, 2022
 *      Author: LENOVO
 */

#ifndef ARM_MCAL_RCC_RCC_PRV_H_
#define ARM_MCAL_RCC_RCC_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define RCC_PLL_BASIC_CLOCK_INPUT_MHZ 84

#define HSEON   16
#define HSEBYP	18
#define CSSON	19
#define HSION	0
#define PLLON	24



#define SW0     0
#define SW1		1


#define RCC_BASE_ADDR 0x40023800

//Defining The Base Address
typedef struct
{
	//RCC_CR register
	u32 CR;

	//RCC_PLLCFGR register
	u32 PLLCFGR;

	//RCC_CFGR register
	u32 CFGR;

	//RCC_CIR register
	u32 CIR;

	//RCC_AHB1RSTR register
	u32 AHB1RSTR;

	//RCC_AHB2RSTR register
	u32 AHB2RSTR;

	//to save the spaces of the memory map
	u32 reserved1;
	u32 reserved2;

	//RCC_APB1RSTR register
	u32 APB1RSTR;

	//RCC_APB2RSTR register
	u32 APB2RSTR;

	u32 reserved3;
	u32 reserved4;

	//RCC_AHB1ENR register
	u32 AHB1ENR;

	//RCC_AHB2ENR register
	u32 AHB2ENR;

	u32 reserved5;
	u32 reserved6;

	//RCC_APB1ENR register
	u32 APB1ENR;

	//RCC_APB2ENR register
	u32 APB2ENR;

	u32 reserved7;
	u32 reserved8;

	//RCC_AHB1LPENR register
	u32 AHB1LPENR;

	//RCC_AHB2LPENR register
	u32 AHB2LPENR;

	u32 reserved9;
	u32 reserved10;

	//RCC_APB1LPENR register
	u32 APB1LPENR;

	//RCC_APB2LPENR register
	u32 APB2LPENR;

	u32 reserved11;
	u32 reserved12;

	//RCC_BDCR register
	u32 BDCR;

	//RCC_CSR register
	u32 CSR;

	u32 reserved13;
	u32 reserved14;

	//RCC_SSCGR register
	u32 SSCGR;

	//RCC_PLLI2SCFGR register
	u32 PLLI2SCFGR;

	u32 reserved15;
	u32 reserved16;

}RCC_MemMap_t;

//to access the struct address as a whole, use arrow operator to access each address individually
#define RCC    ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))



#endif /* ARM_MCAL_RCC_RCC_PRV_H_ */
