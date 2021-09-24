################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Convert.cpp \
../src/Stack.cpp \
../src/assignment_2.cpp 

OBJS += \
./src/Convert.o \
./src/Stack.o \
./src/assignment_2.o 

CPP_DEPS += \
./src/Convert.d \
./src/Stack.d \
./src/assignment_2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


