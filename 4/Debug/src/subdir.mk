################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Stack.cpp \
../src/Tree.cpp \
../src/assignment_4.cpp 

OBJS += \
./src/Stack.o \
./src/Tree.o \
./src/assignment_4.o 

CPP_DEPS += \
./src/Stack.d \
./src/Tree.d \
./src/assignment_4.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


