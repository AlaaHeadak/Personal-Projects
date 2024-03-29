#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI0 0
#define EXTI1 1
#define EXTI2 2
#define EXTI3 3
#define EXTI4 4
#define EXTI5 5
#define EXTI6 6
#define EXTI7 7
#define EXTI8 8
#define EXTI9 9
#define EXTI10 10
#define EXTI11 11
#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15

#define FALLING_EDGE 0
#define RISING_EDGE 1
#define ON_CHANGE_EDGE 2

void MEXTI_voidConfig(u8 copy_u8EXTILine, u8 copy_u8PORT, u8 copy_u8SenseMode);
void EXTI0_VidSetCallBack(void (*ptr)(void));
void MEXTI_voidDisable(u8 copy_u8EXTILine);

#endif /* EXTI_INTERFACE_H_ */
