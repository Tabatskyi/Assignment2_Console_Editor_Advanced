#include "Insert.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


Insert::Insert(int line, int column, const char* input)
{
    this->line = line;
    index = column;
    text = new char[strlen(input) + 1];
    strcpy(text, input);
}

void Insert::Do(EditorMemory* memory)
{
    int currentLengthNum = memory->currentLengthNum;
    int currentLinesNum = memory->currentLinesNum;

    char* firstPart = new char[currentLengthNum];
    char* secondPart = new char[currentLengthNum];

    strcpy(firstPart, memory->textMemory[line]);
    firstPart[index] = '\0';

    strcpy(secondPart, memory->textMemory[line] + index);

    while (strlen(firstPart) + strlen(text) + strlen(secondPart) >= currentLengthNum)
        memory->resizeLength();

    strcpy(memory->textMemory[line], strcat(strcat(firstPart, text), secondPart));

    delete[] firstPart;
    delete[] secondPart;
}