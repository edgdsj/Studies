################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/MCP2515/mcp2515_hal.c 

OBJS += \
./Core/MCP2515/mcp2515_hal.o 

C_DEPS += \
./Core/MCP2515/mcp2515_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Core/MCP2515/%.o Core/MCP2515/%.su: ../Core/MCP2515/%.c Core/MCP2515/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/temp/Documentos/Studies/Microcontroller/STMF407VE/communication/F407_BASICCAN/Core/MCP2515LIB" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-MCP2515

clean-Core-2f-MCP2515:
	-$(RM) ./Core/MCP2515/mcp2515_hal.d ./Core/MCP2515/mcp2515_hal.o ./Core/MCP2515/mcp2515_hal.su

.PHONY: clean-Core-2f-MCP2515

