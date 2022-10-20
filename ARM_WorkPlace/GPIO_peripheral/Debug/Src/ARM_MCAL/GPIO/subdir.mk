################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ARM_MCAL/GPIO/GPIO_Program.c 

OBJS += \
./Src/ARM_MCAL/GPIO/GPIO_Program.o 

C_DEPS += \
./Src/ARM_MCAL/GPIO/GPIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/ARM_MCAL/GPIO/%.o Src/ARM_MCAL/GPIO/%.su: ../Src/ARM_MCAL/GPIO/%.c Src/ARM_MCAL/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-ARM_MCAL-2f-GPIO

clean-Src-2f-ARM_MCAL-2f-GPIO:
	-$(RM) ./Src/ARM_MCAL/GPIO/GPIO_Program.d ./Src/ARM_MCAL/GPIO/GPIO_Program.o ./Src/ARM_MCAL/GPIO/GPIO_Program.su

.PHONY: clean-Src-2f-ARM_MCAL-2f-GPIO

