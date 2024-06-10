#pragma once
#include "Memory.h"
class Replace : public RevertableCommand
{
public:
	Replace();
	~Replace();

	void Do(Memory* memory);
	void Undo(Memory* memory);
private:
	unsigned int line, index, count;
	char* replacedText;
};

