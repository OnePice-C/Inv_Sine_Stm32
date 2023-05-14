################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/main.c \
../User/pid.c 

OBJS += \
./User/main.o \
./User/pid.o 

C_DEPS += \
./User/main.d \
./User/pid.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -c -I../Inc -I"F:/STM32_Sine_CubeIDE/F1_project/Lib/CMSIS" -I"F:/STM32_Sine_CubeIDE/F1_project/Lib/inc" -I"F:/STM32_Sine_CubeIDE/F1_project/Lib/lib" -I"F:/STM32_Sine_CubeIDE/F1_project/User" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/main.d ./User/main.o ./User/main.su ./User/pid.d ./User/pid.o ./User/pid.su

.PHONY: clean-User

