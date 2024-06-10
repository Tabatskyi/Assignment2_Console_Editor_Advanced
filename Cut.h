#pragma once
#include "Memory.h"
class Cut : public RevertableCommand
{
public:
	Cut();
	~Cut();

	void Do(Memory* memory);
	void Undo(Memory* memory);
private:
	unsigned int line, index, count;
	char* cuttedText;
};

