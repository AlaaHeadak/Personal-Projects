/*
 * general_configuration.h
 *
 *  Created on: Oct 18, 2022
 *      Author: LENOVO
 */

#ifndef GENERAL_CONFIGURATION_H_
#define GENERAL_CONFIGURATION_H_

/* RCC Config
 * Note: Do not select two types at a time
 *
 */
#define RCC_SYS_CLK_RCC 1
#define RCC_SYS_CLK_HSE 1
#define RCC_SYS_CLK_HSI 0

/* RCC PLLP
 *
 * Note: Available values: 2,4,6,8
 * 		 Unit: MHz
 * 		 Default: 4
 */
#define RCC_PLLP_MHZ_CFG 4

/* 192 ≤ PLLN ≤ 432
 * Default: 432
 */
#define RCC_PLLN_MHZ_CFG 432

/* 2 ≤ PLLM ≤ 63
 *
 * Default: 2
 * */
#define RCC_PLLM_MHZ_CFG 2

#endif /* GENERAL_CONFIGURATION_H_ */
