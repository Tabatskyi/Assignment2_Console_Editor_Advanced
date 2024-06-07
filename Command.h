#pragma once

class Command
{
public:
    virtual ~Command() = default;
    virtual void Do() = 0;
};

