#pragma once
#include "Command.h"

class RevertableCommand : public Command
{
public:
    virtual ~RevertableCommand() = default;
    void Do() {}
    void Undo() {}
};