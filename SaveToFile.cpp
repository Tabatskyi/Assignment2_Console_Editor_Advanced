#include "SaveToFile.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

SaveToFile::SaveToFile(EditorMemory* editorMemory, char* filename)
{
    memory = editorMemory;
    this->filename = filename;
}

SaveToFile::~SaveToFile()
{
    free(file);
}

void SaveToFile::Do()
{
    file = fopen(filename, "w");
    if (file != NULL)
    {
        for (int i = 0; i <= memory->currentLine; i++)
        {
            fprintf(file, "%s\n", memory->textMemory[i]);
        }
        fclose(file);
        printf(">Save successful\n");
    }
    else
    {
        printf(">Error opening file\n");
    }
}