#include "Delete.h"

Delete::Delete(EditorMemory* editorMemory, unsigned int line, unsigned int index, unsigned int symbolsCount)
{
	memory = editorMemory;
	this->line = line;
	this->index = index;
	count = symbolsCount;
	deletedText = new char[count];
}

Delete::~Delete()
{
	delete[] deletedText;
}

void Delete::Do()
{
	
}