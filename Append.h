#pragma once
#include "EditorMemory.h"

class Append : public RevertableCommand
{
public:
    Append(unsigned int currentLine, char* input);

    void Do(EditorMemory* memory);
    void Undo(EditorMemory* memory);
private:
    int line;
    char* text;
};


