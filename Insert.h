#pragma once
#include "Memory.h"

class Insert : public RevertableCommand
{
public:
	Insert(int line, int column, const char* input);
	~Insert();
	void Do(Memory* memory);
	void Undo(Memory* memory);
private:
	unsigned int line;
	unsigned int index; 
	char* text;

};

