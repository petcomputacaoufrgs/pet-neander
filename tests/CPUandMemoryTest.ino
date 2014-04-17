#include <Arduino.h>
#include "Memory.h"
#include "CPU.h"

Memory theMemory;
CPU theCPU(&theMemory);

void setup()
{
  theMemory.write(0, 32);
  theMemory.write(1, 128);
  theMemory.write(2, 48);
  theMemory.write(3, 129);
  theMemory.write(4, 64);
  theMemory.write(5, 130);
  theMemory.write(6, 80);
  theMemory.write(7, 131);
  theMemory.write(8, 0);
  theMemory.write(9, 128);
  theMemory.write(10, 12);
  theMemory.write(11, 240);
  theMemory.write(12, 144);
  theMemory.write(13, 135);
  theMemory.write(14, 160);
  theMemory.write(15, 135);
  theMemory.write(16, 0);
  theMemory.write(17, 0);
  theMemory.write(18, 32);
  theMemory.write(19, 131);
  theMemory.write(20, 144);
  theMemory.write(21, 23);
  theMemory.write(22, 240);
  theMemory.write(23, 32);
  theMemory.write(24, 130);
  theMemory.write(25, 160);
  theMemory.write(26, 28);
  theMemory.write(27, 240);
  theMemory.write(28, 32);
  theMemory.write(29, 128);
  theMemory.write(30, 16);
  theMemory.write(31, 134);
  theMemory.write(32, 240);
  
  theMemory.write(128, 13);
  theMemory.write(129, 17);
  theMemory.write(130, 0);
  theMemory.write(131, 255);
  theMemory.write(132, 0);
  theMemory.write(133, 0);
  theMemory.write(134, 0);
  theMemory.write(135, 240);
  
  Serial.begin(9600);    
}

void loop()
{
	// Arduino runs a single instruction every time it receives a signal from the serial monitor
	if (Serial.available())
	{
	  Serial.read();
	  
	  theCPU.step();
	  
	  Serial.print("AC: ");
	  Serial.println(theCPU.getAC());
	  Serial.print("PC: ");
	  Serial.println(theCPU.getPC());
	  Serial.print("Memory accesses: ");
	  Serial.println(theMemory.getMemoryAcesses() - 41); // 41 memory accesses to define program
	  Serial.print("Instruction count: ");
	  Serial.println(theCPU.getInstructionCount());
	  Serial.print("N: ");
	  Serial.println(theCPU.getN());
	  Serial.print("Z: ");
	  Serial.println(theCPU.getZ());
	  Serial.println();
	}
}