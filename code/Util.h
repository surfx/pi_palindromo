#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <sys/stat.h>
#include <stdio.h>

class Util
{

public:
    // função tem erro: 418109913393319901814
    // static int isPrime(char *vString)
    // {
    //     int v = atoi(vString);
    //     int m = v / 2;
    //     for (int i = 2; i <= m; i++)
    //     {
    //         if (v % i == 0)
    //         {
    //             return 0; // not
    //         }
    //     }
    //     return 1;
    // }

    static int isPrime(char *vString)
    {
        return isPrime(atoi(vString));
    }

    // https://www.geeksforgeeks.org/c-program-to-check-prime-number/
    static int isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return 0;

        // Check from 2 to n-1
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;

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