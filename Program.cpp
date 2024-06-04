#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "memlib.h"


int main()
{
    char command;
    FILE* file;
    char filename[100];

    Memory memory();

    do
    {
        printf(">");
        (void)scanf(" %c", &command);

        switch (command)
        {
        case 'a':
            Append append(memory);
            append.Do();
            //Append.Save();
            break;

        case 'n':
            printf(">New line started\n");
            if (currentLine < currentLinesNum - 1)
            {
                currentLine++;
            }
            else
            {
                resizeLines();
                currentLine++;
            }
            break;

        case 's':
            printf(">Enter filename for saving: ");
            (void)scanf(" %s", filename);

            file = fopen(filename, "w");
            if (file != NULL)
            {
                for (int i = 0; i <= currentLine; i++)
                {
                    fprintf(file, "%s\n", memory[i]);
                }
                fclose(file);
                printf(">Save successful\n");
            }
            else
            {
                printf(">Error opening file\n");
            }
            break;

        case 'l':
            printf(">Enter filename for loading: ");
            (void)scanf(" %s", filename);

            file = fopen(filename, "r");
            if (file != NULL)
            {
                currentLine = 0;
                while (fgets(inputBuffer, currentLenghNum, file) != NULL)
                {
                    if (currentLine++ >= currentLinesNum)
                    {
                        resizeLines();
                    }
                    inputBuffer[strlen(inputBuffer) - 1] = 0;
                    strcpy(memory[currentLine - 1], inputBuffer);
                }
                fclose(file);
                currentLine--;
                printf(">Load successful\n");
            }
            else
            {
                perror(">Error opening file\n");
            }
            break;

        case 'p':
            for (int i = 0; i <= currentLine; i++)
            {
                printf("%d: %s\n", i, memory[i]);
            }
            break;

        case 'i':
            char* firstPart;
            char* secondPart;
            unsigned int line;
            unsigned int index;

            printf(">Choose line and index: ");
            (void)scanf("%u %u", &line, &index);

            if (line >= currentLinesNum || index >= currentLenghNum)
            {
                printf("Error: Index out of range");
            }

            printf(">Enter text to insert: ");
            (void)scanf(" %[^\n]", inputBuffer);

            firstPart = (char*)malloc(currentLenghNum * sizeof(char));
            secondPart = (char*)malloc(currentLenghNum * sizeof(char));

            strcpy(firstPart, memory[line] + index);
            firstPart[index] = 0;

            strcpy(secondPart, memory[line] + index);

            if (strlen(firstPart) + strlen(inputBuffer) + strlen(secondPart) >= currentLenghNum)
                resizeLength();

            strcpy(memory[line], strcat(strcat(firstPart, inputBuffer), secondPart));

            free(firstPart);
            free(secondPart);
            break;

        case 'f':
            unsigned int position;
            bool found;

            printf(">Enter text to search: ");
            (void)scanf(" %[^\n]", inputBuffer);

            found = false;
            for (int i = 0; i <= currentLine; i++)
            {
                char* result = strstr(memory[i], inputBuffer);

                position = result - memory[i];
                while (result != NULL)
                {
                    position = result - memory[i];
                    printf(">Found occurrence at %u %u\n", i, position);
                    found = true;

                    result = strstr(result + strlen(inputBuffer), inputBuffer);
                }
            }
            if (!found)
            {
                printf(">No occurrence found\n");
            }
            break;

        case 'c':
            freeMemory();
            printf(">Memory cleaned\n");
            initializeMemory();
            break;

        case 'q':
            printf(">Goodbye!\n");
            break;

        default:
            printf(">unknown function\n");
            break;
        }
    } while (command != 'q');

    freeMemory();

    return 0;
}