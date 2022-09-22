#ifndef SALVARCONTROLE_H
#define SALVARCONTROLE_H

#include <iostream>
#include <string>
#include <string.h>

#include "Palindrome.h"
#include "Arquivos.h"

class SalvarControle
{

private:
    std::string FILECONTROLPATH;

public:
    SalvarControle() {}
    SalvarControle(std::string fileControlPath)
    {
        FILECONTROLPATH = fileControlPath;
    }

    void setFileControlPath(std::string fileControlPath)
    {
        FILECONTROLPATH = fileControlPath;
    }

    void saveControl(Palindrome palindrome)
    {
        std::ofstream fout(FILECONTROLPATH);
        fout << palindrome.is << ' ' << palindrome.start << ' ' << palindrome.end << ' ' << palindrome.valor;
        fout.close();
    }

    void saveControl(int is, int start, int end, std::string valor)
    {
        Palindrome ctrl(0, start, end);
        valor.copy(ctrl.valor, valor.length());
        saveControl(ctrl);
    }

    void saveControl(int is, int start, int end, char *valor)
    {
        Palindrome ctrl(0, start, end);
        strcpy(ctrl.valor, valor);
        saveControl(ctrl);
    }

    Palindrome getControl()
    {
        Palindrome item_from_disk;
        std::ifstream fin(FILECONTROLPATH);
        if (!fin.is_open())
        {
            item_from_disk.is = -1;
            return item_from_disk;
        }
        fin >> item_from_disk.is >> item_from_disk.start >> item_from_disk.end >> item_from_disk.valor;
        fin.close();
        return item_from_disk;
    }
};

#endif