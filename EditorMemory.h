#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#include "RevertableCommand.h"

class EditorMemory
{
public:
    EditorMemory(int lines, int length);
    ~EditorMemory();

    int initializeMemory();
    void freeMemory();
    int resizeLines();
    int resizeLength();
    void saveCommand(RevertableCommand command);
    void print();
    void find(char* text);

    unsigned int currentLine; 
    unsigned int currentLinesNum;
    unsigned int currentLengthNum;

    char** textMemory;
    char* clipboard;
    RevertableCommand* commandsMemory;

};

