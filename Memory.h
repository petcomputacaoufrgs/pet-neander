#ifndef MEMORY_H
#define MEMORY_H

#include "Arduino.h"

#define N_WORDS 256

class Memory
{
public:
    Memory(); // constructor
    ~Memory(); // deconstructor
    byte read(byte address);
    void write(byte address, byte value);
	unsigned long getMemoryAcesses();
	
private:
    byte _words[N_WORDS];
	unsigned long _memoryAccesses;
};

#endif // MEMORY_H
