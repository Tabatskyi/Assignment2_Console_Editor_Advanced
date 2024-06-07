#include "Memory.h"

Memory::Memory(unsigned int lines, unsigned int length, unsigned int commandsMemorySize)
{
    undoStep = 1;
    currentLine = 0;
    currentLinesNum = lines;
    currentLengthNum = length;
    this->commandsMemorySize = commandsMemorySize;
 
    initializeMemory();
    initializeCommandsMemory();
}

Memory::~Memory()
{
	freeMemory();
}

void Memory::freeMemory()
{
    for (unsigned int i = 0; i < currentLinesNum; i++)
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
    for (unsigned int i = 0; i < currentLinesNum; i++)
    {
        textMemory[i] = (char*)malloc(currentLengthNum * sizeof(char));
        if (!textMemory[i])
        {
            perror(">Memory allocation failed.\n");
            freeMemory();
            return 1;
        }
        textMemory[i][0] = '\0';
    }
}

int Memory::initializeCommandsMemory()
{
    commandsMemory = new RevertableCommand * [commandsMemorySize];
    if (!commandsMemory)
    {
        perror(">Memory allocation failed.\n");
        return 1;
    }
    for (unsigned int i = 0; i < commandsMemorySize; i++)
    {
        commandsMemory[i] = nullptr;
    }
    return 0; 
}


int Memory::resizeLines()
{
    unsigned int newLinesNum = currentLinesNum * 2;
    char** newMemory = (char**)realloc(textMemory, newLinesNum * sizeof(char*));
    if (!newMemory)
    {
        perror("Memory reallocation failed");
        return 1;
    }

    for (unsigned int i = currentLinesNum; i < newLinesNum; i++)
    {
        newMemory[i] = (char*)malloc(currentLengthNum * sizeof(char));
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
    unsigned int newLengthNum = currentLengthNum * 2;
    for (unsigned int i = 0; i < currentLinesNum; i++)
    {
        char* newLine = (char*)calloc(newLengthNum, sizeof(char));

        strcpy(newLine, textMemory[i]);
        if (!newLine)
        {
            perror("Memory reallocation failed for line resizing");
            return 1;
        }
        textMemory[i] = (char*)calloc(newLengthNum, sizeof(char));
        strcpy(textMemory[i], newLine);
        free(newLine);
    }

    currentLengthNum = newLengthNum;
    printf("Line length resized to %d\n", currentLengthNum);
    return 0;
}

void Memory::print()
{
	for (unsigned int i = 0; i <= currentLine; i++)
	{
		printf("%d: %s\n", i, textMemory[i]);
	}
}

void Memory::find(char* text) 
{
    unsigned int position;
    bool found;

    found = false;
    for (unsigned int i = 0; i <= currentLine; i++)
    {
        char* result = strstr(textMemory[i], text);

        position = result - textMemory[i];
        while (result != NULL)
        {
            position = result - textMemory[i];
            printf(">Found occurrence at %u %u\n", i, position);
            found = true;

            result = strstr(result + strlen(text), text);
        }
    }
    if (!found)
    {
        printf(">No occurrence found\n");
    }
}

void Memory::printCommands() 
{
    std::cout << "Current commands in memory:" << std::endl;
    for (unsigned int i = 0; i < commandsMemorySize; i++) 
    {
        if (commandsMemory[i] != nullptr) 
           std::cout << i << ": Command at " << commandsMemory[i] << std::endl;
        else 
           std::cout << i << ": [Empty]" << std::endl;
    }
}

void Memory::saveCommand(RevertableCommand* command)
{
    std::cout << "Saving command: " << command << std::endl;
    if (undoStep > 1) 
	{
		for (unsigned int i = commandsMemorySize - 1; i >= undoStep; i--) 
		{
			commandsMemory[i] = commandsMemory[i - 1];
		}
        undoStep = 1;
	}
    
    else 
    {
        delete[] commandsMemory[0];

        for (unsigned int i = 1; i < commandsMemorySize; i++)
        {
            commandsMemory[i - 1] = commandsMemory[i];
        }
    }
    

    commandsMemory[commandsMemorySize - 1] = command;
    printCommands();
    
}
void Memory::createClipboard(unsigned int size) 
{
    if (clipboard) 
        delete[] clipboard;

    clipboard = new char[size];
}