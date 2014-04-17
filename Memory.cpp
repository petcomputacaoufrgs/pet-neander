#include "Memory.h"

// constructor
Memory::Memory()
{
	// initializes all words with zero
	for (int i=0; i<N_WORDS; i++)
		_words[i] = 0;
	_memoryAccesses = 0;
}

// deconstructor
Memory::~Memory()
{
// nothing to destruct
}

unsigned long Memory::getMemoryAcesses()
{
	return _memoryAccesses;
}

// reads word from specified address
byte Memory::read(byte address)
{
	_memoryAccesses = _memoryAccesses + 1;
    return _words[address];
}

// writes word to specified address
void Memory::write(byte address, byte value)
{
	_memoryAccesses = _memoryAccesses + 1;
    _words[address] = value;
}