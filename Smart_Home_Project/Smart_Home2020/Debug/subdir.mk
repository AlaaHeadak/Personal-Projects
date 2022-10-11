################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../BUZ_Program.c \
../DIO_Program.c \
../KPD_Program.c \
../LCD_Program.c \
../LDR_Program.c \
../LED_Program.c \
../TEMP_Program.c \
../main.c 

OBJS += \
./ADC_Program.o \
./BUZ_Program.o \
./DIO_Program.o \
./KPD_Program.o \
./LCD_Program.o \
./LDR_Program.o \
./LED_Program.o \
./TEMP_Program.o \
./main.o 

C_DEPS += \
./ADC_Program.d \
./BUZ_Program.d \
./DIO_Program.d \
./KPD_Program.d \
./LCD_Program.d \
./LDR_Program.d \
./LED_Program.d \
./TEMP_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


