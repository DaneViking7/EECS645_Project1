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
    printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
				OpCode,
				Rs,
				Rt,
				Rd );

	printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
				ShiftAmt,
				FunctionCode,
				ImmediateValue );

    // initialize mAnswer
    mAnswer = 0;

    //  R Instruction
	if (OpCode == 0x00)
	{
        switch (FunctionCode)
        {
            // NOOP/SLL
            case 0x00:
                mAnswer = static_cast<unsigned>(Rt) << ShiftAmt;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SRL
            case 0X02:
                mAnswer = static_cast<unsigned>(Rt) >> ShiftAmt;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SRA
            case 0x03:
                mAnswer = static_cast<unsigned>(Rt) >> ShiftAmt;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SLLV
            case 0x04:
                mAnswer = Rt << Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SRLV
            case 0x06:
                mAnswer = Rt >> Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // MFHI
            case 0x10:
                mAnswer = Rt;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            //MFLO
            case 0x12:
                mAnswer = Rs;
                printf( ">>>>>>ALU: mAnswer: %04X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // MULT
            case 0x18:
                mAnswer = Rt * Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // MULTU
            case 0x19:
                mAnswer = static_cast<unsigned>(Rt) * static_cast<unsigned>(Rs);
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            //DIV
            case 0x1A:
                mAnswer = Rt / Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // DIVU
            case 0x1B:
                mAnswer = static_cast<unsigned>(Rt) / static_cast<unsigned>(Rs);
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // ADD
            case 0x20:
                mAnswer = Rt + Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // ADDU
            case 0x21:
                mAnswer = static_cast<unsigned>(Rt) + static_cast<unsigned>(Rs);
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SUB
            case 0x22:
                mAnswer = Rt - Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SUBU
            case 0x23:
                mAnswer = static_cast<unsigned>(Rt) - static_cast<unsigned>(Rs);
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // AND
            case 0x24:
                mAnswer = Rt & Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // OR
            case 0x25:
                mAnswer = Rt | Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // XOR
            case 0x26:
                mAnswer = Rt ^ Rs;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SLT
            case 0x2A:
                if (Rt < Rs)
                {
                    mAnswer = 1;
                }
                else
                {
                    mAnswer = 0;
                }
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SLTU
            case 0x2B:
                if (static_cast<unsigned>(Rt) < static_cast<unsigned>(Rs))
                {
                    mAnswer = 1;
                }
                else
                {
                    mAnswer = 0;
                }
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            default:
                printf( ">>>>>>DEFAULT\n" );
            break;
        }
        std::cout<<std::endl;
	}
    // I Instruction
	else
    {
        switch (OpCode)
        {
            // ADDI
            case 0x08:
                mAnswer = Rt + ImmediateValue;
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // ADDIU
            case 0x09:
                mAnswer = static_cast<unsigned>(Rt) + static_cast<unsigned>(ImmediateValue);
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SLTI
            case 0x0A:
                if (Rt < ImmediateValue)
                {
                    mAnswer = 1;
                }
                else
                {
                    mAnswer = 0;
                }
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            // SLTIU
            case 0x0B:
                if (static_cast<unsigned>(Rt) < static_cast<unsigned>(ImmediateValue))
                {
                    mAnswer = 1;
                }
                else
                {
                    mAnswer = 0;
                }
                printf( ">>>>>>ALU: mAnswer: %08X;\n", mAnswer);
                RegisterFile_Write(theRegisterFile, true, Rd, mAnswer);
            break;

            default:
                printf( ">>>>>>DEFAULT\n" );
            break;
        }
        std::cout<<std::endl;
    }
}
