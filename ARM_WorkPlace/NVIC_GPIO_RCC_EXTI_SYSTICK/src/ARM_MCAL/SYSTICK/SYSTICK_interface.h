#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTICK_INT_H
#define __SYSTICK_INT_H

/******************************************************************************/
/*Function: MSYSTICk_voidConfig                         				  */
/*I/P Parameters: no thing		            								  */
/*Returns:it returns void                            				  */
/*Desc:This Function control SYSTICK Timer depend on pre-configurations	      */
/******************************************************************************/
void MSYSTICk_voidConfig(void);

/******************************************************************************/
/*Function: MSYSTICk_voidEnable                     					  */
/*I/P Parameters: void			            								  */
/*Returns:it returns void                            				  */
/*Desc:This Function enables the SYSTICK Timer						          */
/******************************************************************************/
void MSYSTICk_voidEnable(void);


/******************************************************************************/
/*Function: MSYSTICk_voidDisable                    					  */
/*I/P Parameters: void			            								  */
/*Returns:it returns void                            				  */
/*Desc:This Function disables the SYSTICK Timer						          */
/******************************************************************************/
void MSYSTICk_voidDisable(void);

/******************************************************************************/
/*Function: MSYSTICk_voidPreLoad                          			  */
/*I/P Parameters: copy_u32PreloadValue		            					  */
/*Returns:it returns void                            				  */
/*Desc:This Function control SYSTICK Timer Preload						      */
/******************************************************************************/
void MSYSTICk_voidPreLoad(u32 copy_u32PreloadValue);

/******************************************************************************/
/*Function: MSYSTICK_voidSetBusyWait		                       			  */
/*I/P Parameters: u32 copy_u32Ticks, u8 copy_TickType						  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes a delay for number of ticks(This holds the processor)		      */
/******************************************************************************/
void MSYSTICK_voidSetBusyWait(u32 copy_u32Ticks, u8 copy_TickType);

/***************************************************************************************************/
/*Function: MSYSTICK_voidSetIntervalSingle	                       			    				   */
/*I/P Parameters: u32 copy_u32Ticks, u8 copy_u8TickType ,void (*Copy_ptr)(void) 				   */
/*copy_TickType OPTIONS: NANO_SEC, MILLI_SEC, MICRO_SEC, SEC				    				   */
/*Returns:it returns nothing	                            				    				   */
/*Desc:Makes Async function fires an interrupt after specific time once	        				   */
/***************************************************************************************************/
void MSYSTICK_voidSetIntervalSingle( u32 copy_u32Ticks, u8 copy_u8TickType ,void (*Copy_ptr)(void) );

/***************************************************************************************************/
/*Function: MSYSTICK_voidSetIntervalPeriodic                       			  					   */
/*I/P Parameters: u32 copy_u32Ticks, u8 copy_u32Ticks, void (*Copy_ptr)(void)      				   */
/*copy_TickType OPTIONS: NANO_SEC, MILLI_SEC, MICRO_SEC, SEC				    				   */
/*Returns:it returns nothing	                            				  					   */
/*Desc:Makes Async function fires an interrupt after specific time 		      					   */
/***************************************************************************************************/
void MSYSTICK_voidSetIntervalPeriodic( u32 copy_u32Ticks, u8 copy_u8TickType, void (*Copy_ptr)(void) );

/******************************************************************************/
/*Function: MSYSTICK_voidStopInterval		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes This function stops the periodic events of the SYSTICK timer     */
/******************************************************************************/
void MSYSTICK_voidStopInterval(void);

/******************************************************************************/
/*Function: MSYSTICK_u32GetElapsedTime		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns u32		                            				  */
/*Desc:Makes This function Get the Elapsed Time from the start of the Timer   */
/******************************************************************************/
u32 MSYSTICK_u32GetElapsedTime(void);
/******************************************************************************/
/*Function: MSYSTICK_u32GetRemainingTime	                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns u32		                            				  */
/*Desc:Makes This function Get the remaining Time for the Timer to overflow   */
/******************************************************************************/
u32 MSYSTICK_u32GetRemainingTime(void);
/******************************************************************************/

#endif /* __SYSTICK_INT_H */
