#include "NewLine.h"

NewLine::NewLine(unsigned int currentLine)
{
    line = currentLine + 1;
}

NewLine::~NewLine()
{

}

void NewLine::Do(EditorMemory* memory)
{
    if (line >= memory->currentLinesNum)
        memory->resizeLines();

    memory->currentLine = line;
}