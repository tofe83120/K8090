################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../K8090.cpp \
../K8090Core.cpp \
../K8090Listener.cpp 

OBJS += \
./K8090.o \
./K8090Core.o \
./K8090Listener.o 

CPP_DEPS += \
./K8090.d \
./K8090Core.d \
./K8090Listener.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


