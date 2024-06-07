#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#pragma once

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include <iostream>

class Command
{
public:
    virtual ~Command() = default;
    virtual void Do() = 0;
};


class EditorMemory
{
public:
    EditorMemory(unsigned int lines, unsigned int length, unsigned int commandsMemorySize);
    ~EditorMemory();

    int initializeMemory();
    int initializeCommandsMemory();
    void printCommands();
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


class RevertableCommand : public Command
{
public:
    virtual ~RevertableCommand() = default;

    virtual void Do(EditorMemory* memory) = 0;
    virtual void Undo(EditorMemory* memory) = 0;
};