#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#include "RevertableCommand.h"

class EditorMemory : public Memory
{
public:
    EditorMemory(unsigned int lines, unsigned int length, unsigned int commandsMemorySize);
    ~EditorMemory();

    int initializeMemory();
    int initializeCommandsMemory();
    void freeMemory();
    int resizeLines();
    int resizeLength();
    void saveCommand(RevertableCommand* command);
    void print();
    void find(char* text);
    void createClipboard(unsigned int size);

    unsigned int currentLine; 
    unsigned int currentLinesNum;
    unsigned int currentLengthNum;
    unsigned int commandsMemorySize;

    char** textMemory;
    char* clipboard;
    RevertableCommand** commandsMemory;
    
};

