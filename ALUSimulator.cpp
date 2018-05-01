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
    // initialize members
    mAnswer = 0;
    sVal = 0;
    tVal = 0;
    specialWrite = false;

    //Read the register
    RegisterFile_Read(theRegisterFile, Rs, &sVal, Rt, &tVal);

    // R Instructions
	if (OpCode == 0x00)
	{
        switch (FunctionCode)
        {
            // NOOP/SLL
            case 0x00:
                mAnswer = tVal << ShiftAmt; break;

            // SRL
            case 0X02:
                mAnswer = tVal >> ShiftAmt; break;

            // SRA
            case 0x03:
                mAnswer = tVal >> ShiftAmt; break;

            // SLLV
            case 0x04:
                mAnswer = tVal << sVal; break;

            // SRLV
            case 0x06:
                mAnswer = tVal >> sVal; break;

            // MFHI
            case 0x10:
                // Need to read from HI register 0x1F 
                RegisterFile_Read(theRegisterFile, 0x1F, &sVal, 0x1F, &tVal);
                mAnswer = sVal; break;

            // MFLO
            case 0x12:
                // Need to read from LO register 0x1E
                RegisterFile_Read(theRegisterFile, 0x1E, &sVal, 0X1E, &tVal);
                mAnswer = sVal; break;

            // MULT
            case 0x18:
                mAnswer = sVal * tVal;
                specialWrite = true; 
                // Need to write result of instruction to HI and LO registers
                RegisterFile_Write(theRegisterFile, true, 0x1F, mAnswer);
                RegisterFile_Write(theRegisterFile, true, 0x1E, mAnswer); break;

            // MULTU
            case 0x19:
                mAnswer = sVal * tVal;
                specialWrite = true; 
                // Need to write result of instruction to HI and LO registers
                RegisterFile_Write(theRegisterFile, true, 0x1F, mAnswer);
                RegisterFile_Write(theRegisterFile, true, 0x1E, mAnswer); break;

            // DIV
            case 0x1A:
                mAnswer = sVal / tVal;
                specialWrite = true;
                // Need to write result of instruction to HI and LO registers
                RegisterFile_Write(theRegisterFile, true, 0x1F, mAnswer);
                RegisterFile_Write(theRegisterFile, true, 0x1E, mAnswer); break;

            // DIVU
            case 0x1B:
                mAnswer = sVal / tVal;
                specialWrite = true;
                // Need to write result of instruction to HI and LO registers
                RegisterFile_Write(theRegisterFile, true, 0x1F, mAnswer);
                RegisterFile_Write(theRegisterFile, true, 0x1E, mAnswer); break;

            // ADD
            case 0x20:
                mAnswer = sVal + tVal; break;

            // ADDU
            case 0x21:
                mAnswer = sVal + tVal; break;

            // SUB
            case 0x22:
                mAnswer = sVal - tVal; break;

            // SUBU
            case 0x23:
                mAnswer = sVal - tVal; break;

            // AND
            case 0x24:
                mAnswer = sVal & tVal; break;

            // OR
            case 0x25:
                mAnswer = sVal | tVal; break;

            // XOR
            case 0x26:
                mAnswer = sVal ^ tVal; break;

            // SLT
            case 0x2A:
                if (sVal < tVal) { mAnswer = 1; }
                else { mAnswer = 0; } break;

            // SLTU
            case 0x2B:
                if (sVal < tVal) { mAnswer = 1; }
                else { mAnswer = 0; } break;

            default: /*Do nothing*/ break;
        }

        // Write result of instruction to the register file
        if (!specialWrite) { RegisterFile_Write(theRegisterFile, true, Rd, mAnswer); }
	}
    // I Instructions
	else
    {
        switch (OpCode)
        {
            // ADDI
            case 0x08:
                mAnswer = sVal + ImmediateValue; break;

            // ADDIU
            case 0x09:
                mAnswer = sVal + ImmediateValue; break;

            // SLTI
            case 0x0A:
                if (sVal < ImmediateValue) { mAnswer = 1; }
                else { mAnswer = 0; } break;

            // SLTIU
            case 0x0B:
                if (sVal < ImmediateValue) { mAnswer = 1; }
                else { mAnswer = 0; } break;

            default: /*Do nothing*/ break;
        }

        // Write result of instruction to the register file
        RegisterFile_Write(theRegisterFile, true, Rt, mAnswer);
    }
}