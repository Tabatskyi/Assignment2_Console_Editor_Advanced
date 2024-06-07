#pragma once
#include "Command.h"
#include "Memory.h"

class RevertableCommand : public Command
{
public:
    virtual ~RevertableCommand() = default;

    void Do(Memory* memory) {}
    void Undo(Memory* memory) {}
};