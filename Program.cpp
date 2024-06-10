#include "Memory.h"
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
    Memory memory(128, 256, 3);

    do
    {
        printf(">");
        (void)scanf(" %c", &command);

        if (command == 'a')
        {
            char* inputBuffer = (char*)malloc(memory.currentLengthNum * sizeof(char));
            printf(">Enter text to append: ");
            (void)scanf(" %[^\n]s", inputBuffer);
            Append* append = new Append(memory.currentLine, inputBuffer);
            append->Do(&memory);
            memory.saveCommand(append);
        }
        else if (command == 'n')
        {
            printf(">New line started\n");
            NewLine* newLine = new NewLine(memory.currentLine);
            newLine->Do(&memory);
            memory.saveCommand(newLine);
        }
        else if (command == 's')
        {
            char filename[100];
            printf(">Enter filename for saving: ");
            (void)scanf(" %s", filename);
            SaveToFile* saveToFile = new SaveToFile(filename);
            saveToFile->Do(&memory);
        }
        else if (command == 'l')
        {
            char filename[100];
            printf(">Enter filename for loading: ");
            (void)scanf(" %s", filename);
            LoadFromFile* loadFromFile = new LoadFromFile(filename);
            loadFromFile->Do(&memory);
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
                continue;
            }

            printf(">Enter text to insert: ");
            (void)scanf(" %[^\n]", inputBuffer);

            Insert* insert = new Insert(line, index, inputBuffer);
            insert->Do(&memory);
            memory.saveCommand(insert);
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
                continue;
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
            memory.undoStep++;

            if (memory.undoStep >= size or memory.commandsMemory[size - memory.undoStep] == nullptr)
            {
				printf(">No more commands to undo\n");
				continue;
			}
            memory.commandsMemory[size - memory.undoStep]->Undo(&memory);
        }
        else if (command == 'z')
        {
            unsigned int size = memory.commandsMemorySize;
            if (memory.undoStep == 0)
			{
				printf(">No more commands to redo\n");
				continue;
			}
            memory.commandsMemory[size - memory.undoStep]->Do(&memory);
            memory.undoStep--;
        }
        else if (command == 'x')
        {
            //cut
        }
        else if (command == 'c')
        {
            unsigned int line, index, symbolsCount;

            printf(">Choose line, index and symbols count: ");
            (void)scanf("%u %u %u", &line, &index, &symbolsCount);

            if (line >= memory.currentLinesNum || index >= memory.currentLengthNum)
            {
                printf("Error: Index out of range");
                continue;
            }

            Copy* copy = new Copy(line, index, symbolsCount);
            copy->Do(&memory);
            memory.saveCommand(copy);
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

    delete &memory;

    return 0;
}
