################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32f0xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f0xx.c 

OBJS += \
./Src/main.o \
./Src/stm32f0xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f0xx.o 

C_DEPS += \
./Src/main.d \
./Src/stm32f0xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F030K6Tx -DSTM32F030 -DUSE_STDPERIPH_DRIVER -c -I"F:/STM32_Sine_CubeIDE/F0_Sine_Demo_exit__2/Inc" -I"F:/STM32_Sine_CubeIDE/F0_Sine_Demo_exit__2/Libraries/Code_CM0" -I"F:/STM32_Sine_CubeIDE/F0_Sine_Demo_exit__2/Libraries/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32f0xx_it.d ./Src/stm32f0xx_it.o ./Src/stm32f0xx_it.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f0xx.d ./Src/system_stm32f0xx.o ./Src/system_stm32f0xx.su

.PHONY: clean-Src

