#pragma once
#include "EditorMemory.h"

class NewLine : public RevertableCommand
{
public:
    NewLine(unsigned int currentLine);

    void Do(EditorMemory* memory);
    void Undo(EditorMemory* memory);
private:
    int line;
};



