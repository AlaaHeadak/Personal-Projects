/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTICK_CONF_H
#define __SYSTICK_CONF_H

/*********************************************/
/* SYSTICK_ENABLE OPTIONS:  ENABLE           */
/*                          DISABLE          */
/*********************************************/
#define SYSTICK_ENABLE	        ENABLE

/*********************************************/
/* SYSTICK_TICKINT OPTIONS:  ENABLE          */
/*                           DISABLE         */
/*********************************************/
#define SYSTICK_TICKINT         DISABLE


/*********************************************/
/* SYSTICK_CLK OPTIONS: AHB_CLK              */
/*			            AHB_DIVIDED_BY_8_CLK */
/*********************************************/
#define SYSTICK_CLK		AHB_DIVIDED_BY_8_CLK
/*********************************************/

/*********************************************/
/*  	CTRL_REG Bit Mapping                 */
/*********************************************/
#define STK_CTRL_ENABLE_BIT 	  0
#define STK_CTRL_TICKINT_BIT      1
#define STK_CTRL_CLKSOURCE_BIT    2
#define STK_CTRL_COUNTFLAG_BIT    16
/*********************************************/

/*********************************************/
/*Returns 1 if timer counted to 0 since last */
/* time this was read.						 */
/*********************************************/
#define SYSTICK_COUNT_FLAG        1

/*********************************************/
/*  	Pre-Load configurations              */
/*********************************************/
#define PRELOAD_ENABLE            0
#define PRELOAD_VALUE             10000
#define PRELOAD_IMMEDIATE		  1

#define NANO_SEC                    0
#define MILLI_SEC                   1
#define MICRO_SEC                   2
#define SEC                         3

#define CLOCK_IN_MHZ 8


#endif /* __SYSTICK_CONF_H */
