#include "Delete.h"
#include "Insert.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


Delete::Delete(unsigned int line, unsigned int index, unsigned int symbolsCount)
{
	this->line = line;
	this->index = index;
	count = symbolsCount;
	deletedText = new char[count];
}

Delete::~Delete()
{
}

void Delete::Do(EditorMemory* memory)
{
    int currentLengthNum = memory->currentLengthNum;
    int currentLinesNum = memory->currentLinesNum;

    char* firstPart = new char[currentLengthNum];
    char* secondPart = new char[currentLengthNum];

    strncpy(firstPart, memory->textMemory[line], index);
    firstPart[index] = '\0';

    strncpy(deletedText, memory->textMemory[line] + index, count);
    deletedText[count] = '\0';

    strncpy(secondPart, memory->textMemory[line] + index + count, currentLengthNum - index - count);
    secondPart[currentLengthNum - index - count] = '\0';

    strcpy(memory->textMemory[line], strcat(firstPart, secondPart));

    delete[] firstPart;
    delete[] secondPart;
}

void Delete::Undo(EditorMemory* memory)
{
    Insert insert(line, index, deletedText);
    insert.Do(memory);
}
