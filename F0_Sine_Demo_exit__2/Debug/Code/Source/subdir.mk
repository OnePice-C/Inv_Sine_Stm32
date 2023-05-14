################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Source/stm32f0xx_adc.c \
../Code/Source/stm32f0xx_gpio.c \
../Code/Source/stm32f0xx_misc.c \
../Code/Source/stm32f0xx_rcc.c \
../Code/Source/stm32f0xx_tim.c 

OBJS += \
./Code/Source/stm32f0xx_adc.o \
./Code/Source/stm32f0xx_gpio.o \
./Code/Source/stm32f0xx_misc.o \
./Code/Source/stm32f0xx_rcc.o \
./Code/Source/stm32f0xx_tim.o 

C_DEPS += \
./Code/Source/stm32f0xx_adc.d \
./Code/Source/stm32f0xx_gpio.d \
./Code/Source/stm32f0xx_misc.d \
./Code/Source/stm32f0xx_rcc.d \
./Code/Source/stm32f0xx_tim.d 


# Each subdirectory must supply rules for building sources it contributes
Code/Source/%.o Code/Source/%.su: ../Code/Source/%.c Code/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F030K6Tx -DSTM32F030 -DUSE_STDPERIPH_DRIVER -c -I../Inc -I"F:/Documents_CubeIDE/F0_Sine_Demo/Code/Code_CM0" -I"F:/Documents_CubeIDE/F0_Sine_Demo/Code/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Code-2f-Source

clean-Code-2f-Source:
	-$(RM) ./Code/Source/stm32f0xx_adc.d ./Code/Source/stm32f0xx_adc.o ./Code/Source/stm32f0xx_adc.su ./Code/Source/stm32f0xx_gpio.d ./Code/Source/stm32f0xx_gpio.o ./Code/Source/stm32f0xx_gpio.su ./Code/Source/stm32f0xx_misc.d ./Code/Source/stm32f0xx_misc.o ./Code/Source/stm32f0xx_misc.su ./Code/Source/stm32f0xx_rcc.d ./Code/Source/stm32f0xx_rcc.o ./Code/Source/stm32f0xx_rcc.su ./Code/Source/stm32f0xx_tim.d ./Code/Source/stm32f0xx_tim.o ./Code/Source/stm32f0xx_tim.su

.PHONY: clean-Code-2f-Source

