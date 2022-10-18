/*
 * RCC_Program.c
 *
 *  Created on: Oct 18, 2022
 *      Author: LENOVO
 */

#include "RCC_Interface.h"
#include "RCC_Prv.h"
#include "RCC_Configuration.h"


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


void MRCC_vInit(void)
{
	// 1- CSS (on/off)
	SET_BIT(RCC->CR,CSSON);

	// 2- DISABLE HSE ByPass(RCC_CR)
	CLR_BIT(RCC->CFGR,HSEBYP);

	// 3- Select clock (RCC_CFGR) (HSI or HSE or PLL)
	SET_BIT(RCC->CFGR,SW0);


	// 4- Bus pre-scalar & PLL Configuration (RCC_PLLCFGR)
	// 4.0 Check F_MAX:

	// 4.1 Config "PLLP" Bits:
	RCC_PLLCFGR_PLL_P();
	// 4.2 Config "PLLN" Bits:
	RCC_PLLCFGR_PLL_N();
	// 4.3 Config "PLLM" Bits:
	RCC_PLLCFGR_PLL_M();

	u32 GEN_clock_output;

	GEN_clock_output=(VCO*RCC_PLLCFGR_PLL_N())/(RCC_PLLCFGR_PLL_M()*RCC_PLLCFGR_PLL_P());
	if (GEN_clock_output<=RCC_PLL_BASIC_CLOCK_INPUT_MHZ)
	{
		//GEN_clock_output;
	}
	else
	{
		GEN_clock_output=RCC_PLL_BASIC_CLOCK_INPUT_MHZ;
	}


	// 5- enable the selected clock (RCC_CR)
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR,HSEON);
#endif


}

//(RCC_AHB1ENR)
void MRCC_vEnableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,A_u32PeripheralId ) ;
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,A_u32PeripheralId ) ;
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,A_u32PeripheralId ) ;
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,A_u32PeripheralId ) ;
		break;
	default:
		/* Error: Bus ID out of range */
		break;
	}

}

void MRCC_vDisableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
	{
		switch(A_u32BusId)
		{
		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,A_u32PeripheralId ) ;
			break;
		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,A_u32PeripheralId ) ;
			break;
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,A_u32PeripheralId ) ;
			break;
		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,A_u32PeripheralId ) ;
			break;
		}
}




