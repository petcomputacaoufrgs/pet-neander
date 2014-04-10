#ifndef DECODER_H
#define DECODER_H

#include "Arduino.h"

enum Instruction
{
	NOP,
	STA,
	LDA,
	ADD,
	OR,
	AND,
	NOT,
	JMP,
	JN,
	JZ,
	HLT,
	INVALID
};
	
class Decoder
{
public:
	Decoder();
	~Decoder();
	Instruction getInstruction(byte value);
private: 

};	

#endif // DECODER_H