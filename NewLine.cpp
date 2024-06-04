#include "NewLine.h"

NewLine::NewLine(EditorMemory* mem)
{
    memory = mem;
    line = memory->currentLine + 1;
}

NewLine::~NewLine()
{

}

void NewLine::Do()
{
    if (line >= memory->currentLinesNum)
        memory->resizeLines();

    memory->currentLine = line;
}