################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/src/misc.c \
../User/src/pid.c \
../User/src/stm32f10x_adc.c \
../User/src/stm32f10x_gpio.c \
../User/src/stm32f10x_rcc.c \
../User/src/stm32f10x_tim.c 

OBJS += \
./User/src/misc.o \
./User/src/pid.o \
./User/src/stm32f10x_adc.o \
./User/src/stm32f10x_gpio.o \
./User/src/stm32f10x_rcc.o \
./User/src/stm32f10x_tim.o 

C_DEPS += \
./User/src/misc.d \
./User/src/pid.d \
./User/src/stm32f10x_adc.d \
./User/src/stm32f10x_gpio.d \
./User/src/stm32f10x_rcc.d \
./User/src/stm32f10x_tim.d 


# Each subdirectory must supply rules for building sources it contributes
User/src/%.o User/src/%.su: ../User/src/%.c User/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -c -I../Inc -I"F:/STM32_Sine_CubeIDE/F1_Sine_Timer1_BCT/User/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-src

clean-User-2f-src:
	-$(RM) ./User/src/misc.d ./User/src/misc.o ./User/src/misc.su ./User/src/pid.d ./User/src/pid.o ./User/src/pid.su ./User/src/stm32f10x_adc.d ./User/src/stm32f10x_adc.o ./User/src/stm32f10x_adc.su ./User/src/stm32f10x_gpio.d ./User/src/stm32f10x_gpio.o ./User/src/stm32f10x_gpio.su ./User/src/stm32f10x_rcc.d ./User/src/stm32f10x_rcc.o ./User/src/stm32f10x_rcc.su ./User/src/stm32f10x_tim.d ./User/src/stm32f10x_tim.o ./User/src/stm32f10x_tim.su

.PHONY: clean-User-2f-src

