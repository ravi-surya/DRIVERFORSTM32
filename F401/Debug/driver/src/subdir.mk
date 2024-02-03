################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/RCC_Config.c 

OBJS += \
./driver/src/RCC_Config.o 

C_DEPS += \
./driver/src/RCC_Config.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o driver/src/%.su driver/src/%.cyclo: ../driver/src/%.c driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/ravis/Desktop/DRIVERFORSTM32/F401/driver/inc" -I"C:/Users/ravis/Desktop/DRIVERFORSTM32/F401/driver/src" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-src

clean-driver-2f-src:
	-$(RM) ./driver/src/RCC_Config.cyclo ./driver/src/RCC_Config.d ./driver/src/RCC_Config.o ./driver/src/RCC_Config.su

.PHONY: clean-driver-2f-src

