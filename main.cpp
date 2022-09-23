#include <iostream>
#include <string>

#include "code/PalindromoAnalise.h"
#include "code/Util.h"

using namespace std;

const char FILECONTROLPATH[] = "/home/emerson/Desktop/eme/projetos/pi_palindromo/arquivos/controle/controle.txt";
// const char FILEPATH[] = "/home/emerson/Desktop/eme/projetos/picpp/arquivos/Pi - Dec.txt";
const char FILEPATH[] = "/home/emerson/Documents/pi_files/saida4.txt";

void findPalindrome()
{
    PalindromoAnalise analise(FILEPATH, FILECONTROLPATH, false);
    // Palindrome isP = analise.ispalidrome(9, true); // is: 1 [129080,129088]: '318272813'
    Palindrome isP = analise.ispalidrome(21, true); // is: 1 [576111091,576111111]: '418109913393319901814' - não é primo (!)

    isP.print();
}

int main()
{
    findPalindrome();
    return 0;
}