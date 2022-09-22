#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <sys/stat.h>
#include <stdio.h>

class Util
{

public:
    static int isPrime(char *vString)
    {
        int v = atoi(vString);
        int m = v / 2;
        for (int i = 2; i <= m; i++)
        {
            if (v % i == 0)
            {
                return 0; // not
            }
        }
        return 1;
    }

    static bool file_exists(const std::string &name)
    {
        struct stat buffer;
        return (stat(name.c_str(), &buffer) == 0);
    }

    static bool removeFile(const std::string fileNameStr)
    {
        char fileName[fileNameStr.length() + 1];
        strcpy(fileName, fileNameStr.c_str());
        return remove(fileName) == 0;
    }
};

#endif