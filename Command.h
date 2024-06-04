#pragma once

class Command
{
public:
    virtual ~Command() {}
    void Do() {}
}; 


//class SaveToFile : Command
//{
//public:
//    SaveToFile(Memory* mem, char* filen)
//    {
//        memory = mem;
//        filename = filen;
//    };
//    ~SaveToFile();
//
//    void Do();
//private:
//    Memory* memory;
//    FILE* file;
//    char* filename;
//};
//
//void SaveToFile::Do()
//{
//    file = fopen(filename, "w");
//    if (file != NULL)
//    {
//        for (int i = 0; i <= memory->currentLine; i++)
//        {
//            fprintf(file, "%s\n", memory[i]);
//        }
//        fclose(file);
//        printf(">Save successful\n");
//    }
//    else
//    {
//        printf(">Error opening file\n");
//    }
//}
//
//
//class LoadFromFile : Command
//{
//public:
//    LoadFromFile(Memory* mem, char* filen)
//    {
//        memory = mem;
//        filename = filen;
//        text = (char*)malloc(memory->currentLenghNum * sizeof(char));
//    };
//    ~LoadFromFile();
//
//    void Do();
//
//private:
//    Memory* memory;
//    FILE* file;
//    char* filename;
//    char* text;
//};
//
//void LoadFromFile::Do()
//{
//    file = fopen(filename, "r");
//    if (file != NULL)
//    {
//        memory->currentLine = 0;
//        while (fgets(text, memory->currentLenghNum, file) != NULL)
//        {
//            if (memory->currentLine++ >= memory->currentLinesNum)
//            {
//                memory->resizeLines();
//            }
//            text[strlen(text) - 1] = 0;
//            strcpy(memory->textMemory[memory->currentLine - 1], text);
//        }
//        fclose(file);
//        memory->currentLine--;
//        printf(">Load successful\n");
//    }
//    else
//    {
//        perror(">Error opening file\n");
//    }
//}
