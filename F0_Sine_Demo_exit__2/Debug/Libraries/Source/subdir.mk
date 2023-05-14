################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Source/pid.c \
../Libraries/Source/stm32f0xx_adc.c \
../Libraries/Source/stm32f0xx_dma.c \
../Libraries/Source/stm32f0xx_exti.c \
../Libraries/Source/stm32f0xx_gpio.c \
../Libraries/Source/stm32f0xx_misc.c \
../Libraries/Source/stm32f0xx_rcc.c \
../Libraries/Source/stm32f0xx_syscfg.c \
../Libraries/Source/stm32f0xx_tim.c 

OBJS += \
./Libraries/Source/pid.o \
./Libraries/Source/stm32f0xx_adc.o \
./Libraries/Source/stm32f0xx_dma.o \
./Libraries/Source/stm32f0xx_exti.o \
./Libraries/Source/stm32f0xx_gpio.o \
./Libraries/Source/stm32f0xx_misc.o \
./Libraries/Source/stm32f0xx_rcc.o \
./Libraries/Source/stm32f0xx_syscfg.o \
./Libraries/Source/stm32f0xx_tim.o 

C_DEPS += \
./Libraries/Source/pid.d \
./Libraries/Source/stm32f0xx_adc.d \
./Libraries/Source/stm32f0xx_dma.d \
./Libraries/Source/stm32f0xx_exti.d \
./Libraries/Source/stm32f0xx_gpio.d \
./Libraries/Source/stm32f0xx_misc.d \
./Libraries/Source/stm32f0xx_rcc.d \
./Libraries/Source/stm32f0xx_syscfg.d \
./Libraries/Source/stm32f0xx_tim.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Source/%.o Libraries/Source/%.su: ../Libraries/Source/%.c Libraries/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F030K6Tx -DSTM32F030 -DUSE_STDPERIPH_DRIVER -c -I"F:/STM32_Sine_CubeIDE/F0_Sine_Demo_exit__2/Inc" -I"F:/STM32_Sine_CubeIDE/F0_Sine_Demo_exit__2/Libraries/Code_CM0" -I"F:/STM32_Sine_CubeIDE/F0_Sine_Demo_exit__2/Libraries/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-Source

clean-Libraries-2f-Source:
	-$(RM) ./Libraries/Source/pid.d ./Libraries/Source/pid.o ./Libraries/Source/pid.su ./Libraries/Source/stm32f0xx_adc.d ./Libraries/Source/stm32f0xx_adc.o ./Libraries/Source/stm32f0xx_adc.su ./Libraries/Source/stm32f0xx_dma.d ./Libraries/Source/stm32f0xx_dma.o ./Libraries/Source/stm32f0xx_dma.su ./Libraries/Source/stm32f0xx_exti.d ./Libraries/Source/stm32f0xx_exti.o ./Libraries/Source/stm32f0xx_exti.su ./Libraries/Source/stm32f0xx_gpio.d ./Libraries/Source/stm32f0xx_gpio.o ./Libraries/Source/stm32f0xx_gpio.su ./Libraries/Source/stm32f0xx_misc.d ./Libraries/Source/stm32f0xx_misc.o ./Libraries/Source/stm32f0xx_misc.su ./Libraries/Source/stm32f0xx_rcc.d ./Libraries/Source/stm32f0xx_rcc.o ./Libraries/Source/stm32f0xx_rcc.su ./Libraries/Source/stm32f0xx_syscfg.d ./Libraries/Source/stm32f0xx_syscfg.o ./Libraries/Source/stm32f0xx_syscfg.su ./Libraries/Source/stm32f0xx_tim.d ./Libraries/Source/stm32f0xx_tim.o ./Libraries/Source/stm32f0xx_tim.su

.PHONY: clean-Libraries-2f-Source

