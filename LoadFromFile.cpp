#include "LoadFromFile.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

LoadFromFile::LoadFromFile(EditorMemory* editorMemory, char* filename)
{
    memory = editorMemory;
    this->filename = filename;
    text = new char[memory->currentLengthNum];
}

LoadFromFile::~LoadFromFile()
{
    delete[] text;
}

void LoadFromFile::Do()
{
    file = fopen(filename, "r");
    if (file != NULL)
    {
        memory->currentLine = 0;
        while (fgets(text, memory->currentLengthNum, file) != NULL)
        {
            if (memory->currentLine++ >= memory->currentLinesNum)
            {
                memory->resizeLines();
            }
            text[strlen(text) - 1] = 0;
            strcpy(memory->textMemory[memory->currentLine - 1], text);
        }
        fclose(file);
        memory->currentLine--;
        printf(">Load successful\n");
    }
    else
    {
        perror(">Error opening file\n");
    }
}
