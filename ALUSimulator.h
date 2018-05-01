//*****************************************************************************
//--ALUSimulator.cpp
//
//		Authors: 		Natalie LaLuzerne, Niels Hansen
//		Organization:	KU/EECS/EECS 645
//		Date:			2018-05-03
//		Version:		1.0
//		Description:	This is the  ALU simulator header file
//		Notes:
//
//*****************************************************************************
//

#ifndef ALUSIMULATOR_H
#define ALUSIMULATOR_H

#include "RegisterFile_01.h"

class ALUSimulator
{
public:
    ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status );
private:
	uint32_t mAnswer; //variable which will temporarily store the result of an instruction
	uint32_t sVal; //variable which will temporarily store the Rs value from the register file
	uint32_t tVal; //variable which will temporarily store the Rt value from the register file
};

#endif
