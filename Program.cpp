#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include <iostream>

#include "BasicLib.h"
#include "Append.h"
#include "NewLine.h"
#include "SaveToFile.h"
#include "LoadFromFile.h"
#include "Insert.h"
#include "Delete.h"
#include "Copy.h"
#include "Cut.h"
#include "Paste.h"
#include "Replace.h"

// known bugs: 
// insert to empty line cause infinity increase of memory
// quit cause heap corruption


int main()
{
    char command;
    EditorMemory memory(128, 256, 3);
    unsigned int undoStep = 1;

    do
    {
        printf(">");
        (void)scanf(" %c", &command);

        if (command == 'a')
        {
            char* inputBuffer = (char*)malloc(memory.currentLengthNum * sizeof(char));
            printf(">Enter text to append: ");
            (void)scanf(" %[^\n]s", inputBuffer);
            Append append(memory.currentLine, inputBuffer);
            append.Do(&memory);
            //Append.Save(&memory);
        }
        else if (command == 'n')
        {
            printf(">New line started\n");
            NewLine newLine(memory.currentLine);
            newLine.Do(&memory);
            //newLine.Save(&memory);
        }
        else if (command == 's')
        {
            char filename[100];
            printf(">Enter filename for saving: ");
            (void)scanf(" %s", filename);
            SaveToFile saveToFile(filename);
            saveToFile.Do(&memory);
        }
        else if (command == 'l')
        {
            char filename[100];
            printf(">Enter filename for loading: ");
            (void)scanf(" %s", filename);
            LoadFromFile loadFromFile(filename);
            loadFromFile.Do(&memory);
        }
        else if (command == 'p')
        {
            memory.print();
        }
        else if (command == 'i')
        {
            char* inputBuffer = (char*)malloc(memory.currentLengthNum * sizeof(char));
            unsigned int line, index;

            printf(">Choose line and index: ");
            (void)scanf("%u %u", &line, &index);

            if (line >= memory.currentLinesNum || index >= memory.currentLengthNum)
            {
                printf("Error: Index out of range");
            }

            printf(">Enter text to insert: ");
            (void)scanf(" %[^\n]", inputBuffer);

            Insert insert(line, index, inputBuffer);
            insert.Do(&memory);
            //insert.Save();
        }
        else if (command == 'f')
        {
            char* inputBuffer = (char*)malloc(memory.currentLengthNum * sizeof(char));
            printf(">Enter text to search: ");
            (void)scanf(" %[^\n]", inputBuffer);

            memory.find(inputBuffer);
        }
        else if (command == 'd')
        {
            unsigned int line, index, symbolsCount;

            printf(">Choose line, index and symbols count: ");
            (void)scanf("%u %u %u", &line, &index, &symbolsCount);

            if (line >= memory.currentLinesNum || index >= memory.currentLengthNum)
            {
                printf("Error: Index out of range");
            }
            else
            {
                Delete* deleteCommand = new Delete(line, index, symbolsCount);
                deleteCommand->Do(&memory);
                memory.saveCommand(deleteCommand);
            }
        }
        else if (command == 'u')
        {
            unsigned int size = memory.commandsMemorySize;
            memory.printCommands();
            RevertableCommand* udoingCommand = memory.commandsMemory[size - undoStep];
            std::cout << "Undoing command: " << udoingCommand << std::endl;
            udoingCommand->Undo(&memory);
            undoStep++;
        }
        else if (command == 'z')
        {
            undoStep--;
            unsigned int size = memory.commandsMemorySize;
            memory.commandsMemory[size - undoStep]->Do(&memory);
        }
        else if (command == 'x')
        {
            //cut
        }
        else if (command == 'c')
        {
            //copy
        }
        else if (command == 'v')
        {
            //paste
        }
		else if (command == 'r')
		{
            //replace
		}
        else if (command == 'e')
        {
            memory.freeMemory();
            memory.currentLine = 0;

            printf(">Memory erased\n");
            
            memory.initializeMemory();
        }
        else if (command == 'q')
        {
            printf(">Goodbye!\n");
        }
        else 
            printf(">unknown command\n");

    } while (command != 'q');

    memory.freeMemory();

    return 0;
}
