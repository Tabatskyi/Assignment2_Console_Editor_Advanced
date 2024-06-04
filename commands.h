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
    Append(Memory memoryObj)
    {
        memory = memoryObj;
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
