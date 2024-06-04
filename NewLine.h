#pragma once
#include "EditorMemory.h"

class NewLine : public RevertableCommand
{
public:
    NewLine(EditorMemory* mem);
    ~NewLine();

    void Do();
    void Undo();
    void Save();
private:
    int line;
    EditorMemory* memory;
};



