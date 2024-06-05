#include "Append.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

Append::Append(EditorMemory* mem, char* input)
{
    memory = mem;
    line = memory->currentLine;
    text = input;
}

Append::~Append() 
{
    //free(text);
}

void Append::Do()
{
    if (strlen(memory->textMemory[line]) + strlen(text) < memory->currentLenghNum)
    {
        strcat(memory->textMemory[line], text);
    }
    else
    {
        memory->resizeLength();
        strcat(memory->textMemory[line], text);
    }
}