#include "Memory.h"

// constructor
Memory::Memory()
{
	// initializes all words with zero
	for (int i=0; i<N_WORDS; i++)
		_words[i] = 0;
}

// deconstructor
Memory::~Memory()
{
// nothing to destruct
}

// reads word from specified address
byte Memory::read(byte address)
{
    return _words[address];
}

// writes word to specified address
void Memory::write(byte address, byte value)
{
    _words[address] = value;
}
