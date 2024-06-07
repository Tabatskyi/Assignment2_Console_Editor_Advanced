#pragma once
#include "BasicLib.h"

class LoadFromFile : Command
{
public:
    LoadFromFile(char* filename);
    ~LoadFromFile();

    void Do(EditorMemory* memory);
private:
    char* filename;
};