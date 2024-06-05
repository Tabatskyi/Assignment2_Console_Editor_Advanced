#pragma once
#include "EditorMemory.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


class LoadFromFile : Command
{
public:
    LoadFromFile(EditorMemory* mem, char* filen);
    ~LoadFromFile();

    void Do();

private:
    EditorMemory* memory;
    FILE* file;
    char* filename;
    char* text;
};