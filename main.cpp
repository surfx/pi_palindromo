#include <iostream>

#include "code/PalindromoAnalise.h"

using namespace std;

const char FILECONTROLPATH[] = "/home/emerson/Desktop/eme/projetos/pi_palindromo/arquivos/controle/controle.txt";
// const char FILEPATH[] = "/home/emerson/Desktop/eme/projetos/picpp/arquivos/Pi - Dec.txt";
//  const char FILEPATH[] = "/home/emerson/Desktop/eme/projetos/picpp/arquivos/Pi - Dec.txt"; // lenght: 1000000002
const char FILEPATH[] = "/home/emerson/Documents/pi_files/saida0.txt";

void findPalindrome()
{
    PalindromoAnalise analise(FILEPATH, FILECONTROLPATH, false);
    // Palindrome isP = analise.ispalidrome(9, true); // is: 1 [129080,129088]: '318272813'
    Palindrome isP = analise.ispalidrome(21, true);
    isP.print();
}

int main()
{
    findPalindrome();
    return 0;
}