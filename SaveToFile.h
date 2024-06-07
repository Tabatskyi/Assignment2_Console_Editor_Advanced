#pragma once
#include "BasicLib.h"

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




