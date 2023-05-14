################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user/main.c 

OBJS += \
./user/main.o 

C_DEPS += \
./user/main.d 


# Each subdirectory must supply rules for building sources it contributes
user/%.o user/%.su: ../user/%.c user/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F030K6Tx -DSTM32F030 -DUSE_STDPERIPH_DRIVER -c -I../Inc -I"F:/STM32_Sine_CubeIDE/F0_Demo/Libraries/CMSIS" -I"F:/STM32_Sine_CubeIDE/F0_Demo/Libraries/CMSIS/Include" -I"F:/STM32_Sine_CubeIDE/F0_Demo/Libraries/STM32F0xx_StdPeriph_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-user

clean-user:
	-$(RM) ./user/main.d ./user/main.o ./user/main.su

.PHONY: clean-user

