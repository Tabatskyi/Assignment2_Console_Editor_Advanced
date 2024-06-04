#include "EditorMemory.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

EditorMemory::EditorMemory(int lines, int lenght)
{
    currentLine = 0;
    currentLinesNum = lines;
    currentLenghNum = lenght;
    commandsMemory = (RevertableCommand*)malloc(3 * sizeof(RevertableCommand));
    initializeMemory();
}

EditorMemory::~EditorMemory()
{
	freeMemory();
}

void EditorMemory::freeMemory()
{
    for (int i = 0; i < currentLinesNum; i++)
    {
        free(textMemory[i]);
    }
    free(textMemory);
    free(commandsMemory);
}

int EditorMemory::initializeMemory()
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


int EditorMemory::resizeLines()
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


int EditorMemory::resizeLength()
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