#ifndef PALINDROME_H
#define PALINDROME_H

#include <iostream>

class Palindrome
{

public:
    int is, start, end;
    char valor[20];

    Palindrome(int is_in = 0, int start_in = 0, int end_in = 0)
        : is(is_in), start(start_in), end(end_in) {}

    void print()
    {
        if (is == 0)
        {
            std::cout << "is: " << is << std::endl;
            return;
        }
     
        std::cout << "is: " << is << " [" << start << "," << end << "]: '" << valor << "'" << std::endl;
    }

};

#endif