#pragma once
#include "EditorMemory.h"

class Append : public RevertableCommand
{
public:
    Append(EditorMemory* mem, char* input);
    ~Append();

    void Do();
    void Undo();
    void Save();
private:
    EditorMemory* memory;
    int line;
    char* text;
};


