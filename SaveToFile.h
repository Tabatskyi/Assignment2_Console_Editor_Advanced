#pragma once
#include "EditorMemory.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

class SaveToFile : Command
{
public:
    SaveToFile(EditorMemory* mem, char* filen);
    ~SaveToFile();

    void Do();
private:
    EditorMemory* memory;
    FILE* file;
    char* filename;
};




