#pragma once
#include "Command.h"

class RevertableCommand : public Command
{
public:
    virtual ~RevertableCommand() {}
    void Do() {};
    void Undo() {};
    void Save() {};
};