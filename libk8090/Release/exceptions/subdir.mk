################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../exceptions/DataReadException.cpp \
../exceptions/DataWriteException.cpp \
../exceptions/DeviceCloseException.cpp \
../exceptions/DeviceDetachException.cpp \
../exceptions/DeviceOpenException.cpp \
../exceptions/DeviceReleaseException.cpp \
../exceptions/DeviceResetException.cpp \
../exceptions/IncorrectRelayAddressException.cpp \
../exceptions/IncorrectTimerDelayException.cpp \
../exceptions/InterfaceClaimException.cpp \
../exceptions/InterfaceReleaseException.cpp \
../exceptions/K8090Exception.cpp \
../exceptions/MissingBoardException.cpp 

OBJS += \
./exceptions/DataReadException.o \
./exceptions/DataWriteException.o \
./exceptions/DeviceCloseException.o \
./exceptions/DeviceDetachException.o \
./exceptions/DeviceOpenException.o \
./exceptions/DeviceReleaseException.o \
./exceptions/DeviceResetException.o \
./exceptions/IncorrectRelayAddressException.o \
./exceptions/IncorrectTimerDelayException.o \
./exceptions/InterfaceClaimException.o \
./exceptions/InterfaceReleaseException.o \
./exceptions/K8090Exception.o \
./exceptions/MissingBoardException.o 

CPP_DEPS += \
./exceptions/DataReadException.d \
./exceptions/DataWriteException.d \
./exceptions/DeviceCloseException.d \
./exceptions/DeviceDetachException.d \
./exceptions/DeviceOpenException.d \
./exceptions/DeviceReleaseException.d \
./exceptions/DeviceResetException.d \
./exceptions/IncorrectRelayAddressException.d \
./exceptions/IncorrectTimerDelayException.d \
./exceptions/InterfaceClaimException.d \
./exceptions/InterfaceReleaseException.d \
./exceptions/K8090Exception.d \
./exceptions/MissingBoardException.d 


# Each subdirectory must supply rules for building sources it contributes
exceptions/%.o: ../exceptions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


