################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Candidato.cpp \
../Empresa.cpp \
../Jurado.cpp \
../Participacao.cpp \
../Pessoa.cpp \
../Sessao.cpp \
../main.cpp \
../menus.cpp \
../utils.cpp 

OBJS += \
./Candidato.o \
./Empresa.o \
./Jurado.o \
./Participacao.o \
./Pessoa.o \
./Sessao.o \
./main.o \
./menus.o \
./utils.o 

CPP_DEPS += \
./Candidato.d \
./Empresa.d \
./Jurado.d \
./Participacao.d \
./Pessoa.d \
./Sessao.d \
./main.d \
./menus.d \
./utils.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


