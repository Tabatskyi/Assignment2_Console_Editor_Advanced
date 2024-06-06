#pragma once
#include "EditorMemory.h"
#include <stdio.h>

class SaveToFile : Command
{
public:
    SaveToFile(EditorMemory* editorMemory, char* filename);
    ~SaveToFile();

    void Do();
private:
    EditorMemory* memory;
    FILE* file;
    char* filename;
};




