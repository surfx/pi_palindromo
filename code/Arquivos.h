#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <string>
#include <fstream>

class Arquivos
{

private:
    std::ifstream file;

public:
    Arquivos() {}
    Arquivos(std::string filePath) { file.open(filePath); }

    void open_file(std::string filePath)
    {
        file.open(filePath);
    }

    void close()
    {
        if (!file.is_open())
        {
            return;
        }
        file.close();
    }

    bool is_open()
    {
        return file.is_open();
    }

    char *readString(int posInitial, int posFinal)
    {
        int length = posFinal - posInitial;
        file.seekg(posInitial);

        char *buffer = new char[length + 1];
        file.read(buffer, length + 1);
        buffer[length + 1] = 0;
        return buffer;
    }

    char *readPos(int pos)
    {
        file.seekg(pos);
        char *rt = new char[1];
        file.read(rt, 1);
        return rt;
    }

    int fileLength()
    {
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);
        return length;
    }
};

#endif