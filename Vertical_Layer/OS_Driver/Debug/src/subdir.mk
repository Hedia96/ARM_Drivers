################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/App1.c \
../src/App2.c \
../src/Delay_ms.c \
../src/GPIO_prog.c \
../src/OS_prog.c \
../src/RCC_prog.c \
../src/SYSTICK_prog.c \
../src/main.c 

OBJS += \
./src/App1.o \
./src/App2.o \
./src/Delay_ms.o \
./src/GPIO_prog.o \
./src/OS_prog.o \
./src/RCC_prog.o \
./src/SYSTICK_prog.o \
./src/main.o 

C_DEPS += \
./src/App1.d \
./src/App2.d \
./src/Delay_ms.d \
./src/GPIO_prog.d \
./src/OS_prog.d \
./src/RCC_prog.d \
./src/SYSTICK_prog.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


