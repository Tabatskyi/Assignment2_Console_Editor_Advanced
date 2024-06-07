#pragma once

class Memory
{
public:
    virtual ~Memory() = 0;

    virtual int initializeMemory() = 0;
    virtual int initializeCommandsMemory() = 0;
    virtual void printCommands() = 0;
    virtual void freeMemory() = 0;
    virtual int resizeLines() = 0;
    virtual int resizeLength() = 0;
    virtual void saveCommand(RevertableCommand* command) = 0;
    virtual void print() = 0;
    virtual void find(char* text) = 0;
    virtual void createClipboard(unsigned int size) = 0;

    unsigned int currentLine;
    unsigned int currentLinesNum;
    unsigned int currentLengthNum;
    unsigned int commandsMemorySize;

    char** textMemory;
    char* clipboard;
    RevertableCommand** commandsMemory;
};