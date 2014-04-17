#ifndef CPU_H
#define CPU_H

#include "Arduino.h"
#include "Memory.h"

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

class CPU
{
public:
	CPU(Memory* theMemory); // constructor
    ~CPU(); // deconstructor
	boolean step();
	void run();
	
	//getters
	byte getAC();
	byte getPC();
	unsigned long getInstructionCount();
	boolean getN();
	boolean getZ();

private:
	byte _AC;
	byte _PC;
	unsigned long _instructionCount;
	boolean _N;
	boolean _Z;
	
	void updateNZ();
	
	Instruction decode(byte value);
	Memory* _memory;
};

#endif // CPU_H