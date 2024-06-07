#pragma once
#include "BasicLib.h"

class Insert : public RevertableCommand
{
public:
	Insert(int line, int column, const char* input);

	void Do(EditorMemory* memory);
	void Undo(EditorMemory* memory);
private:
	unsigned int line;
	unsigned int index; 
	char* text;

};

