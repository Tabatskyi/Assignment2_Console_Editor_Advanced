#pragma once
#include "EditorMemory.h"
#include <stdio.h>

class SaveToFile : Command
{
public:
    SaveToFile(char* filename);
    ~SaveToFile();

    void Do(EditorMemory* memory);
private:
    FILE* file;
    char* filename;
};




