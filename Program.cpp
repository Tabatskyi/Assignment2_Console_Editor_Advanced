#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "EditorMemory.h"
#include "Append.h"
#include "NewLine.h"
#include "SaveToFile.h"
#include "LoadFromFile.h"
#include "Insert.h"

// known bugs: 
// insert to empty line cause infinity increase of memory
// quit cause heap corruption


int main()
{
    char command;
    EditorMemory memory(128, 256);

    do
    {
        printf(">");
        (void)scanf(" %c", &command);

        if (command == 'a')
        {
            char* inputBuffer = (char*)malloc(memory.currentLenghNum * sizeof(char));
            printf(">Enter text to append: ");
            (void)scanf(" %[^\n]s", inputBuffer);
            Append append(&memory, inputBuffer);
            append.Do();
            //Append.Save();
        }
        else if (command == 'n')
        {
            printf(">New line started\n");
            NewLine newLine(&memory);
            newLine.Do();
            //newLine.Save();
        }
        else if (command == 's')
        {
            char filename[100];
            printf(">Enter filename for saving: ");
            (void)scanf(" %s", filename);
            SaveToFile saveToFile(&memory, filename);
            saveToFile.Do();
        }
        else if (command == 'l')
        {
            char filename[100];
            printf(">Enter filename for loading: ");
            (void)scanf(" %s", filename);
            LoadFromFile loadFromFile(&memory, filename);
            loadFromFile.Do();
        }
        else if (command == 'p')
        {
            memory.print();
        }
        else if (command == 'i')
        {
            char* inputBuffer = (char*)malloc(memory.currentLenghNum * sizeof(char));
            unsigned int line;
            unsigned int index;

            printf(">Choose line and index: ");
            (void)scanf("%u %u", &line, &index);

            if (line >= memory.currentLinesNum || index >= memory.currentLenghNum)
            {
                printf("Error: Index out of range");
            }

            printf(">Enter text to insert: ");
            (void)scanf(" %[^\n]", inputBuffer);

            Insert insert(&memory, line, index, inputBuffer);
            insert.Do();
            //insert.Save();
        }
        else if (command == 'f')
        {
            char* inputBuffer = (char*)malloc(memory.currentLenghNum * sizeof(char));
            printf(">Enter text to search: ");
            (void)scanf(" %[^\n]", inputBuffer);

            memory.find(inputBuffer);
        }
        else if (command == 'c')
        {
            memory.freeMemory();
            memory.currentLine = 0;

            printf(">Memory cleaned\n");
            
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
