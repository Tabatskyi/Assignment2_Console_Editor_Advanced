#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#include "RevertableCommand.h"

class EditorMemory
{
public:
    EditorMemory(int lines, int lenght);
    ~EditorMemory();

    int initializeMemory();
    void freeMemory();
    int resizeLines();
    int resizeLength();
    void print();

    int currentLine; 
    int currentLinesNum;
    int currentLenghNum;

    char** textMemory;
    RevertableCommand* commandsMemory;
};

