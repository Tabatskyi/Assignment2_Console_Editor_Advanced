#pragma once
#include "EditorMemory.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


class LoadFromFile : Command
{
public:
    LoadFromFile(char* filename);
    ~LoadFromFile();

    void Do(EditorMemory* memory);
private:
    char* filename;
};