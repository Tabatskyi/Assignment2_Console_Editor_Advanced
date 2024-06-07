#pragma once

class Command
{
public:
    virtual ~Command() = default;
    void Do() {}
};