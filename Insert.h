#pragma once
#include "EditorMemory.h"

class Insert : public RevertableCommand
{
public:
	Insert(EditorMemory* mem, int line, int column, char* input);
	~Insert();

	void Do();
	void Undo();
	void Save();
private:
	EditorMemory* memory;
	unsigned int line;
	unsigned int index; 
	char* text;

};

