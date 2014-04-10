#include "Decoder.h"

Instruction Decoder::getInstruction(byte value)
{
	byte shiftedWord = value >> 4; // instruction is defined by the leftmost 4 bits 
	switch (shiftedWord)
	{
		case 0: return NOP;
		case 1: return STA;
		case 2: return LDA;
		case 3: return ADD;
		case 4: return OR;
		case 5: return AND;
		case 6: return NOT;
		// case 7: 
		case 8: return JMP;
		case 9: return JN;
		case 10: return JZ;
		// case 11:
		// case 12:
		// case 13:
		// case 14:
		case 15: return HLT;
		default: return INVALID;
	}
}