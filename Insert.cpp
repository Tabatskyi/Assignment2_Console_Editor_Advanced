#include "Insert.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

Insert::Insert(EditorMemory* mem, int line, int column, char* input)
{
	memory = mem;
	this->line = line;
	this->index = column;
	text = input;
}

Insert::~Insert()
{
	free(text);
}

void Insert::Do()
{
    char* firstPart;
    char* secondPart;
    int currentLenghNum = memory->currentLenghNum;
    int currentLinesNum = memory->currentLinesNum;

    firstPart = (char*)malloc(currentLenghNum * sizeof(char));
    secondPart = (char*)malloc(currentLenghNum * sizeof(char));

    strcpy(firstPart, memory->textMemory[line] + index);
    firstPart[index] = 0;

    strcpy(secondPart, memory->textMemory[line] + index);

    while (strlen(firstPart) + strlen(text) + strlen(secondPart) >= currentLenghNum)
        memory->resizeLength();

    strcpy(memory->textMemory[line], strcat(strcat(firstPart, text), secondPart));

    free(firstPart);
    free(secondPart);
}