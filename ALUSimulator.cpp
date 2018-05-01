//*****************************************************************************
//--ALUSimulator.cpp
//
//		Authors: 		Natalie LaLuzerne, Niels Hansen
//		Organization:	KU/EECS/EECS 645
//		Date:			2018-05-03
//		Version:		1.0
//		Description:	This is the  ALU simulator
//		Notes:
//
//*****************************************************************************
//
#include "ALUSimulator.h"

ALUSimulator::ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status )
{
    // initialize mAnswer
    mAnswer = 0;

    //  R Instruction
	if (OpCode == 0x00)
	{
        switch (FunctionCode)
        {
            // NOOP/SLL
            case 0x00:
                mAnswer = Rt << ShiftAmt;
            break;

            // SRL
            case 0X02:
                mAnswer = Rt >> ShiftAmt;
            break;

            // SRA
            case 0x03:
                mAnswer = Rt >> ShiftAmt;
            break;

            // SLLV
            case 0x04:
                mAnswer = Rt << Rs;
            break;

            // SRLV
            case 0x06:
                mAnswer = Rt >> Rs;
            break;

            // MFHI
            case 0x10:
                mAnswer = Rt;
            break;

            //MFLO
            case 0x12:
                mAnswer = Rs;
            break;

            // MULT
            case 0x18:
                mAnswer = Rt * Rs;
            break;

            // MULTU
            case 0x19:
                mAnswer = Rt * Rs;
            break;

            //DIV
            case 0x1A:
                mAnswer = Rt / Rs;

            break;

            // DIVU
            case 0x1B:
                mAnswer = Rt / Rs;

            break;

            // ADD
            case 0x20:
                mAnswer = Rt + Rs;
            break;

            // ADDU
            case 0x21:

            break;

            // SUB
            case 0x22:

            break;

            // SUBU
            case 0x23:

            break;

            // AND
            case 0x24:

            break;

            // OR
            case 0x25:

            break;

            // XOR
            case 0x26:

            break;

            // SLT
            case 0x2A:

            break;

            // SLTU
            case 0x2B:

            break;

            default:

            break;
        }
	}
    // I Instruction
	else
    {
        switch (OpCode)
        {
            // ADDI
            case 0x08:

            break;

            // ADDIU
            case 0x09:

            break;

            // SLTI
            case 0x0A:

            break;

            case 0x0B:

            break;

            default:

            break;
        }
    }
}
