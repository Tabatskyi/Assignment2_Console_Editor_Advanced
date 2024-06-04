#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


class Command
{
public:
    virtual ~Command() {}
    void Do() {}
};


class RevertableCommand : public Command
{
public:
    virtual ~RevertableCommand() {}
    void Do() {};
    void Undo() {};
    void Save() {};
};


class Append : public RevertableCommand
{
public:
    Append(Memory mem)
    {
        memory = mem;
        line = memory.currentLine;
        text = (char*)malloc(memory.currentLenghNum * sizeof(char));
    }
    ~Append()
    {
        free(text);
    }

    void Do();
    void Undo();
    void Save();
private:
    Memory memory;
    int line;
    char* text;
};

void Append::Do()
{
    printf(">Enter text to append: ");
    (void)scanf(" %[^\n]s", text);

    if (strlen(memory.textArray[line]) + strlen(text) < memory.currentLenghNum)
    {
        strcat(memory.textArray[line], text);
    }
    else
    {
        memory.resizeLength();
        strcat(memory.textArray[line], text);
    }
}


class NewLine : public RevertableCommand 
{
public:
    NewLine(Memory mem) 
    {
        memory = mem;
        line = memory.currentLine + 1;  
    }
    ~NewLine();

    void Do();
    void Undo();
    void Save();
private:
    int line;
    Memory memory;
};

void NewLine::Do()
{
    printf(">New line started\n");
    if (line >= memory.currentLinesNum)
        memory.resizeLines();
    
    memory.currentLine = line;
}


class SaveToFile : Command
{
public:
    SaveToFile(Memory mem) 
    {
        memory = mem;
    };
    ~SaveToFile();

    void Do();
private:
    Memory memory;
    FILE* file;
    char filename[100];
};

void SaveToFile::Do()
{
    printf(">Enter filename for saving: ");
    (void)scanf(" %s", filename);

    file = fopen(filename, "w");
    if (file != NULL)
    {
        for (int i = 0; i <= memory.currentLine; i++)
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
}


class LoadFromFile : Command 
{
public:
    LoadFromFile(Memory mem) 
    {
        memory = mem;
        text = (char*)malloc(memory.currentLenghNum * sizeof(char));
    };
    ~LoadFromFile();

    void Do();

private:
    Memory memory;
    FILE* file;
    char filename[100];
    char* text;
};

void LoadFromFile::Do() 
{
    printf(">Enter filename for loading: ");
    (void)scanf(" %s", filename);

    file = fopen(filename, "r");
    if (file != NULL)
    {
        memory.currentLine = 0;
        while (fgets(text, memory.currentLenghNum, file) != NULL)
        {
            if (memory.currentLine++ >= memory.currentLinesNum)
            {
                memory.resizeLines();
            }
            text[strlen(text) - 1] = 0;
            strcpy(memory[memory.currentLine - 1], text);
        }
        fclose(file);
        memory.currentLine--;
        printf(">Load successful\n");
    }
    else
    {
        perror(">Error opening file\n");
    }
}
