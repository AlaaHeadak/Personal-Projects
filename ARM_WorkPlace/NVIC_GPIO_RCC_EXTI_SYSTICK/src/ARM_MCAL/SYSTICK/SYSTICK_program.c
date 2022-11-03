#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "SYSTICK_interface.h"
#include "SYSTICK_configuration.h"
#include "SYSTICK_private.h"
// ----------------------------------------------------------------------------
f32 Global_f32Counter = 0;
u8 Global_u8TickType = 0;
u32 Global_u32Ticks = 0;
void (*Global_ptr)(void);

/******************************************************************************/
/*Function: MSYSTICk_voidConfig                          			  */
/*I/P Parameters: no thing		            								  */
/*Returns:it returns void                            				  */
/*Desc:This Function control SYSTICK Timer depend on pre-configurations	      */
/******************************************************************************/
void MSYSTICk_voidConfig(void)
{

/* Enable The SYSTICK Timer Interrupt */
#if (SYSTICK_TICKINT == ENABLE)
	SET_BIT(STK->CTRL, STK_CTRL_TICKINT_BIT);
/* Disable The SYSTICK Timer Interrupt */
#elif (SYSTICK_TICKINT == DISABLE)
	CLR_BIT(STK->CTRL, STK_CTRL_TICKINT_BIT);
#endif

#if (SYSTICK_CLK == AHB_CLK)
	/* The SYSTICK Timer Clock Source is AHB */
	SET_BIT(STK->CTRL, STK_CTRL_CLKSOURCE_BIT);

#elif (SYSTICK_CLK == AHB_DIVIDED_BY_8_CLK)
	/* The SYSTICK Timer Clock Source is AHB/8 */
	CLR_BIT(STK->CTRL, STK_CTRL_CLKSOURCE_BIT);

#endif

/*Pre-Load setting during initialization */
#if (PRELOAD_ENABLE)
	STK->LOAD = PRELOAD_VALUE;
#endif
}

/******************************************************************************/
/*Function: MSYSTICk_voidEnable                     					      */
/*I/P Parameters: void			            								  */
/*Returns:it returns void                            				          */
/*Desc:This Function enables the SYSTICK Timer						          */
/******************************************************************************/
void MSYSTICk_voidEnable(void)
{

	/* Enable The SYSTICK Timer */
	SET_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);
}

/******************************************************************************/
/*Function: MSYSTICk_voidDisable                     				          */
/*I/P Parameters: void			            								  */
/*Returns:it returns void                            				          */
/*Desc:This Function disables the SYSTICK Timer						          */
/******************************************************************************/
void MSYSTICk_voidDisable(void)
{
	/* Disable The SYSTICK Timer */
	CLR_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);
}
/******************************************************************************/
/*Function: MSYSTICk_voidPreLoad                          			  */
/*I/P Parameters: copy_u32PreloadValue		            					  */
/*Returns:it returns void                            				  */
/*Desc:This Function control SYSTICK Timer Preload						      */
/******************************************************************************/
void MSYSTICk_voidPreLoad(u32 copy_u32PreloadValue)
{

/*IF required immediately update the value register*/
#if (PRELOAD_IMMEDIATE)

	STK->LOAD = copy_u32PreloadValue;
	STK->VAL = PRELOAD_VALUE;

/*After this iteration required to change the pre-load value*/
#else
	{
		STK->LOAD = copy_u32PreloadValue;
	}
#endif
}

/******************************************************************************/
/*Function: MSYSTICK_voidSetBusyWait		                          		  */
/*I/P Parameters: u32 copy_u32Ticks, u8 copy_TickType						  */
/*copy_TickType OPTIONS: NANO_SEC, MILLI_SEC, MICRO_SEC, SEC				  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes a delay for number of ticks(This holds the processor)		      */
/******************************************************************************/
void MSYSTICK_voidSetBusyWait(u32 copy_u32Ticks, u8 copy_u8TickType)
{
#if (SYSTICK_CLK == AHB_DIVIDED_BY_8_CLK)
	f32 local_f32TickTime = 1 / (CLOCK_IN_MHZ / 8);
#else

	f32 local_f32TickTime = 1 / CLOCK_IN_MHZ;
#endif
	u32 local_NoOfTicks = copy_u32Ticks / local_f32TickTime;

	if (copy_u8TickType == MILLI_SEC)
	{
		copy_u32Ticks = local_NoOfTicks * 1000;
	}

	else if (copy_u8TickType == MICRO_SEC)
	{
		copy_u32Ticks = local_NoOfTicks;
	}
	else if (copy_u8TickType == SEC)
	{
		copy_u32Ticks = local_NoOfTicks * 1000000;
	}
	else
	{
	}

	if (copy_u32Ticks < 16777216)
	{
		setbusy(copy_u32Ticks);
	}
	else if (copy_u32Ticks > 16777216)
	{
		while (copy_u32Ticks > 0)
		{

			if (copy_u32Ticks > 16777215)
			{
				setbusy(16777215);
				copy_u32Ticks -= 16777215;
			}
			else
			{
				setbusy(copy_u32Ticks);
				copy_u32Ticks = 0;
			}
		}
	}
}

void setbusy(u32 copy_u32Ticks)
{
	/* Update the Load registers with number of Ticks or counts */
	STK->LOAD = 0x00000000;
	STK->LOAD = copy_u32Ticks;
	STK->VAL = PRELOAD_VALUE;

	/* Enable the Timer */
	SET_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);

	/* Polling on the flag of the timer */
	while (GET_BIT(STK->CTRL, STK_CTRL_COUNTFLAG_BIT) == 0)
		;

	/* Disable the counter */
	CLR_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);

	/* update the pre-load value with 0 */
	STK->LOAD = 0;
	STK->VAL = 0;
}

/***************************************************************************************************/
/*Function: MSYSTICK_voidSetIntervalSingle	                       			    				   */
/*I/P Parameters: u32 copy_u32Ticks, u8 copy_u8TickType ,void (*Copy_ptr)(void) 				   */
/*copy_TickType OPTIONS: NANO_SEC, MILLI_SEC, MICRO_SEC, SEC				    				   */
/*Returns:it returns nothing	                            				    				   */
/*Desc:Makes Async function fires an interrupt after specific time once	        				   */
/***************************************************************************************************/
void MSYSTICK_voidSetIntervalSingle(u32 copy_u32Ticks, u8 copy_u8TickType, void (*Copy_ptr)(void))
{
#if (SYSTICK_CLK == AHB_DIVIDED_BY_8_CLK)
	f32 local_f32TickTime = 1 / (CLOCK_IN_MHZ / 8);
#else

	f32 local_f32TickTime = 1 / CLOCK_IN_MHZ;
#endif
	u32 local_NoOfTicks = copy_u32Ticks / local_f32TickTime;

	if (copy_u8TickType == MILLI_SEC)
	{
		copy_u32Ticks = local_NoOfTicks * 1000;
	}

	else if (copy_u8TickType == MICRO_SEC)
	{
		copy_u32Ticks = local_NoOfTicks;
	}
	else if (copy_u8TickType == SEC)
	{
		copy_u32Ticks = local_NoOfTicks * 1000000;
	}
	else
	{
	}

	if (copy_u32Ticks < 16777216)
	{
		/* Disable the counter */
		CLR_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);
		STK->VAL = 0;
		/* Update the Load registers with number of Ticks or counts */
		STK->LOAD = copy_u32Ticks;

		/* Enable the Timer */
		SET_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);

		/* Save CallBack */
		SYSTICK_CallBack = Copy_ptr;
		/* Set Mode to Single */
		SYSTICK_u8ModeOfInterval = SYSTICK_SINGLE_INTERVAL;

		/* Enable the interrupt */
		SET_BIT(STK->CTRL, STK_CTRL_TICKINT_BIT);
	}
}

/***************************************************************************************************/
/*Function: MSYSTICK_voidSetIntervalPeriodic	                       			  				   */
/*I/P Parameters: u32 copy_u32Ticks, u8 copy_u32Ticks, void (*Copy_ptr)(void)      				   */
/*copy_TickType OPTIONS: NANO_SEC, MILLI_SEC, MICRO_SEC, SEC				    				   */
/*Returns:it returns nothing	                            				  					   */
/*Desc:Makes Async function fires an interrupt after specific time 		      					   */
/***************************************************************************************************/
void MSYSTICK_voidSetIntervalPeriodic(u32 copy_u32Ticks, u8 copy_u8TickType, void (*Copy_ptr)(void))
{
#if (SYSTICK_CLK == AHB_DIVIDED_BY_8_CLK)
	f32 local_f32TickTime = 1 / (CLOCK_IN_MHZ / 8);
#else

	f32 local_f32TickTime = 1 / CLOCK_IN_MHZ;
#endif
	u32 local_NoOfTicks = copy_u32Ticks / local_f32TickTime;

	if (copy_u8TickType == MILLI_SEC)
	{
		copy_u32Ticks = local_NoOfTicks * 1000;
	}

	else if (copy_u8TickType == MICRO_SEC)
	{
		copy_u32Ticks = local_NoOfTicks;
	}
	else if (copy_u8TickType == SEC)
	{
		copy_u32Ticks = local_NoOfTicks * 1000000;
	}
	else
	{
	}

	if (copy_u32Ticks < 16777216)
	{
		/* Update the Load registers with number of Ticks or counts */
		STK->LOAD = copy_u32Ticks;

		/* Enable the Timer */
		SET_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);

		/* Save CallBack */
		SYSTICK_CallBack = Copy_ptr;

		/* Set Mode to Single */
		SYSTICK_u8ModeOfInterval = SYSTICK_PERIOD_INTERVAL;

		/* Enable the Interrupt */
		SET_BIT(STK->CTRL, STK_CTRL_TICKINT_BIT);
	}
}

/******************************************************************************/
/*Function: MSYSTICK_voidStopInterval		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes This function stops the periodic events of the SYSTICK timer     */
/******************************************************************************/
void MSYSTICK_voidStopInterval(void)
{
	/* Disable the Interrupt */
	CLR_BIT(STK->CTRL, STK_CTRL_TICKINT_BIT);

	/* Disable the Timer */
	CLR_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);

	/* update the pre-load value with 0 */
	STK->LOAD = 0;
	STK->VAL = 0;
}

/******************************************************************************/
/*Function: MSYSTICK_u32GetElapsedTime		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns u32		                            				  */
/*Desc:Makes This function Get the Elapsed Time from the start of the Timer   */
/******************************************************************************/
u32 MSYSTICK_u32GetElapsedTime(void)
{
	/* Local variable to get the elapsed time in it */
	u32 Local_u32ElapsedTime = 0;

	/*Reading the elapsed time form SYSTICK registers*/
	Local_u32ElapsedTime = ((STK->LOAD) - (STK->VAL));

	/*Returning the Control to the caller function with the elapsed time*/
	return Local_u32ElapsedTime;
}

/******************************************************************************/
/*Function: MSYSTICK_u32GetRemainingTime		                       		  */
/*I/P Parameters: void						            					  */
/*Returns:it returns u32		                            				  */
/*Desc:Makes This function Get the remaining Time for the Timer to overflow   */
/******************************************************************************/
u32 MSYSTICK_u32GetRemainingTime(void)
{
	/* Local variable to get the remaining time in it */
	u32 Local_u32RemainTime;

	/*Reading the remaining time form SYSTICK registers*/
	Local_u32RemainTime = STK->VAL;

	/*Returning the Control to the caller function with the remaining time*/
	return Local_u32RemainTime;
}

/******************************************************************************/
/*Function: MSysTick_Handler		                       			          */
/*I/P Parameters: void						            					  */
/*Returns:it returns Nothing		                            			  */
/*Desc: ISR Handler of Systick												  */
/******************************************************************************/
void SysTick_Handler(void)
{
	/* Local Variable to clear the flag with it */
	u8 Local_u8Temporary;

	if (SYSTICK_u8ModeOfInterval == SYSTICK_SINGLE_INTERVAL)
	{
		/* Disable the Interrupt */
		CLR_BIT(STK->CTRL, STK_CTRL_TICKINT_BIT);

		/* Disable the Timer */
		CLR_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);

		/* update the pre-load value with 0 */
		STK->LOAD = 0;
		STK->VAL = 0;
	}

	/* Callback notification */
	SYSTICK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL, STK_CTRL_COUNTFLAG_BIT);
}
