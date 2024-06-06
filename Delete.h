#pragma once
#include "EditorMemory.h"
class Delete : public RevertableCommand
{
public:
	Delete(EditorMemory* editorMemory, unsigned int line, unsigned int index, unsigned int symbolsCount);
	~Delete();

	void Do();
	void Undo();
	void Save();
private:
	EditorMemory* memory;
	unsigned int line;
	unsigned int index;
	unsigned int count;
	char* deletedText;
};

