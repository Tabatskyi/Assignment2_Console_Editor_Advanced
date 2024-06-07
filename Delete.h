#pragma once
#include "Memory.h"
class Delete : public RevertableCommand
{
public:
	Delete(unsigned int line, unsigned int index, unsigned int symbolsCount);
	~Delete();

	void Do(Memory* memory);
	void Undo(Memory* memory);
private:
	unsigned int line;
	unsigned int index;
	unsigned int count;
	char* deletedText;
};

