#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

enum Status
{
	NotRdy = 0,
	Rdy = 1,
	OutOfRange = 2
};

#define HSI 1
#define HSE 2
#define PLL 3

/* System Buses */
#define AHB1 1
#define AHB2 2
#define APB1 3
#define APB2 4

/* AHB1 Peripherals */
#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define GPIODEN 3
#define GPIOEEN 4
#define GPIOHEN 7
#define CRCEN 12
#define DMA1EN 21
#define DMA2EN 22

/* AHB2 Peripherals */
#define OTGFSEN 7

/* APB1 Peripherals */
#define TIM2EN 0
#define TIM3EN 1
#define TIM4EN 2
#define TIM5EN 3
#define WWDGEN 11
#define SPI2EN 14
#define SPI3EN 15
#define USART2EN 17
#define I2C1EN 21
#define I2C2EN 22
#define I2C3EN 23
#define PWREN 28

/* APB2 Peripherals */
#define TIM1EN 0
#define USART1EN 4
#define USART6EN 5
#define ADC1EN 8
#define SDIOEN 11
#define SPI1EN 12
#define SPI4EN 13
#define SYSCFGEN 14
#define TIM9EN 16
#define TIM10EN 17
#define TIM11EN 18

void MRCC_voidInit(void);
void MRCC_voidPeripheralEnable(u8 copy_u8Bus, u8 copy_u8Peripheral);
void MRCC_voidPeripheralDisable(u8 copy_u8Bus, u8 copy_u8Peripheral);

/* Set input as a system clock */
void MRCC_voidSetClkSource(u8 copy_u8ClkSource);
/* Turn on and off clock source */
void MRCC_voidSetClkStatus(u8 copy_u8ClkSource, u8 copy_u8Status);
/* Set AHB1 and APB1 and APB2 Prescalers */
void MRCC_voidSetBusesPrescaler(u8 copy_u8AHB, u8 copy_u8APB1, u8 copy_u8APB2);
/* Set PLL Factors */
void MRCC_voidSetPLLFactors(u8 copy_u8PLLM, u8 copy_u8PLLN, u8 copy_u8PLLP, u8 copy_u8PLLQ);

#endif /* RCC_INTERFACE_H_ */
