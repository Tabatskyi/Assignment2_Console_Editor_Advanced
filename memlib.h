#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "commands.h"


class Memory
{
public:
    Memory()
    {
        int currentLine = 0;
        int currentLinesNum = 128;
        int currentLenghNum = 256;
        initializeMemory();
    }
    ~Memory()
    {
        freeMemory();
    }

    int initializeMemory();
    void freeMemory();
    int resizeLines();
    int resizeLength();

    int currentLine;
    int currentLinesNum;
    int currentLenghNum;
    int currentLine;

    char** textMemory;
    RevertableCommand* commandsMemory;

private:
    // make 3d array
    // or array with command classes
    /*char*** memory;
    char** memory0;
    char** memory1;
    char** memory2;
    char** memory3;*/
};

void Memory::freeMemory()
{
    for (int i = 0; i < currentLinesNum; i++)
    {
        free(textMemory[i]);
    }
    free(textMemory);
    free(commandsMemory);
}

int Memory::initializeMemory()
{
    textMemory = (char**)malloc(currentLinesNum * sizeof(char*));
    if (!textMemory)
    {
        perror(">Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < currentLinesNum; i++)
    {
        textMemory[i] = (char*)malloc(currentLenghNum * sizeof(char));
        if (!textMemory[i])
        {
            perror(">Memory allocation failed.\n");
            freeMemory();
            return 1;
        }
        textMemory[i][0] = 0;
    }
}


int Memory::resizeLines()
{
    int newLinesNum = currentLinesNum * 2;
    char** newMemory = (char**)realloc(textMemory, newLinesNum * sizeof(char*));
    if (!newMemory)
    {
        perror("Memory reallocation failed");
        return 1;
    }

    for (int i = currentLinesNum; i < newLinesNum; i++)
    {
        newMemory[i] = (char*)malloc(currentLenghNum * sizeof(char));
        if (!newMemory[i]) {
            perror("Memory allocation failed for new lines");
            return 1;
        }
        newMemory[i][0] = '\0';
    }

    currentLinesNum = newLinesNum;
    textMemory = newMemory;
    printf("Line capacity expanded to %d\n", currentLinesNum);
    return 0;
}


int Memory::resizeLength()
{
    int newLengthNum = currentLenghNum * 2;
    for (int i = 0; i < currentLinesNum; i++)
    {
        char* newLine = (char*)malloc(newLengthNum * sizeof(char));
        strcpy(newLine, textMemory[i]);
        if (!newLine)
        {
            perror("Memory reallocation failed for line resizing");
            return 1;
        }
        textMemory[i] = (char*)malloc(newLengthNum * sizeof(char));
        strcpy(textMemory[i], newLine);
        free(newLine);
    }

    currentLenghNum = newLengthNum;
    printf("Line length resized to %d\n", currentLenghNum);
    return 0;
}
