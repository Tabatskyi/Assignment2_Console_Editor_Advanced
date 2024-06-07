#include "Append.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

Append::Append(unsigned int currentLine, char* input)
{
    text = input;
    line = currentLine;
}

void Append::Do(EditorMemory* memory)
{

    if (strlen(memory->textMemory[line]) + strlen(text) < memory->currentLengthNum)
    {
        strcat(memory->textMemory[line], text);
    }
    else
    {
        memory->resizeLength();
        strcat(memory->textMemory[line], text);
    }
}