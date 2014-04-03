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
private:
    byte _words[N_WORDS];
};

#endif // MEMORY_H
