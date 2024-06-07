#pragma once
#include "EditorMemory.h"
class Delete : public RevertableCommand
{
public:
	Delete(unsigned int line, unsigned int index, unsigned int symbolsCount);

	void Do(EditorMemory* memory);
	void Undo(EditorMemory* memory);
private:
	unsigned int line;
	unsigned int index;
	unsigned int count;
	char* deletedText;
};

