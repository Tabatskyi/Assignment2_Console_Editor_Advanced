#include "Paste.h"
#include "Insert.h"
#include "Delete.h"


Paste::Paste(int line, int column)
{
    this->line = line;
    index = column;
}

Paste::~Paste()
{
    delete[] text;
}

void Paste::Do(Memory* memory) 
{
    text = new char[strlen(memory->clipboard) + 1];
    strcpy(text, memory->clipboard);
	Insert* insert = new Insert(line, index, text);
    insert->Do(memory);
}

void Paste::Undo(Memory* memory)
{
	Delete* deleteCommand = new Delete(line, index, strlen(text));
	deleteCommand->Do(memory);
    delete deleteCommand;
}