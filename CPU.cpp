#include "CPU.h"

// constructor
CPU::CPU(Memory* theMemory)
{
	_AC = 0;
	_PC = 0;
	_instructionCount = 0;
	_N = false;
	_Z = true;
	_memory = theMemory;
}

Instruction CPU::decode(byte value)
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

// runs a single instruction; returns false if the instruction run was a halt
boolean CPU::step()
{
	Instruction currentInstruction = decode(_memory->read(_PC));
	_PC = _PC + 1;
	_instructionCount += 1;
	
	// instruction execution
	switch(currentInstruction)
	{
		case NOP: break;
		case STA:
			_memory->write(_memory->read(_PC), _AC);
			_PC = _PC + 1;
			break;
		case LDA:
			_AC = _memory->read(_memory->read(_PC));
			_PC = _PC + 1;
			updateNZ();
			break;
		case ADD:
			_AC = _AC + _memory->read(_memory->read(_PC));
			_PC = _PC + 1;
			updateNZ();
			break;
		case OR:
			_AC = _AC | _memory->read(_memory->read(_PC));
			_PC = _PC + 1;
			updateNZ();
			break;
		case AND:
			_AC = _AC & _memory->read(_memory->read(_PC));
			_PC = _PC + 1;
			updateNZ();
			break;
		case NOT:
			_AC = ~(_AC);
			_PC = _PC + 1;
			updateNZ();
			break;
		case JMP:
			_PC = _memory->read(_PC);
			break;
		case JN:
			if (_N == true)
				_PC = _memory->read(_PC);
			else
				_PC = _PC + 1;
			break;
		case JZ:
			if (_Z == true)
				_PC = _memory->read(_PC);
			else
				_PC = _PC + 1;
			break;
		case HLT: return false;
		case INVALID: break;
	}
	return true;
}

// run all instructions until a halt is found
void CPU::run()
{
	while(step());
}

void CPU::updateNZ()
{
	if (_AC == 0)
		_Z = true;
	else
		_Z = false;
	
	if ((_AC >> 7) == 1)
		_N = true;
	else
		_N = false;
}

//getters

byte CPU::getAC()
{
	return _AC;
}

byte CPU::getPC()
{
	return _PC;
}

unsigned long CPU::getInstructionCount()
{
	return _instructionCount;
}

boolean CPU::getN()
{
	return _N;
}

boolean CPU::getZ()
{
	return _Z;
}