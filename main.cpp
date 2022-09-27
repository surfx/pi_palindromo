#include <iostream>
#include <string>

#include "code/PalindromoAnalise.h"
#include "code/Util.h"

using namespace std;

const char FILECONTROLPATH[] = "/home/emerson/Desktop/eme/projetos/pi_palindromo/arquivos/controle/controle.txt";
const char PATHFILES[] = "/home/emerson/Documents/pi_files/";
string FILEANALISE = ""; // saida13.txt

void findPalindrome()
{
    PalindromoAnalise analise(FILEANALISE, FILECONTROLPATH, false);
    // Palindrome isP = analise.ispalidrome(9, true); // is: 1 [129080,129088]: '318272813'
    Palindrome isP = analise.ispalidrome(21, true); // is: 1 [576111091,576111111]: '418109913393319901814' - não é primo (!)

    isP.print();
}

int initial(int argc, char **argv)
{
    if (argc <= 2)
    {
        cout << "Informe o nome do arquivo e se deve excluir ou manter o controle (0/1)" << endl;
        return -1;
    }

    const int excluirManterControle = atoi(argv[2]);
    if (excluirManterControle < 0 || excluirManterControle >= 2)
    {
        cout << "Excluir ou manter o controle deve ser 0 ou 1" << endl;
        return -1;
    }

    FILEANALISE = PATHFILES;
    FILEANALISE = FILEANALISE + argv[1];

    if (!Util::file_exists(FILEANALISE))
    {
        cout << "O arquivo '" << FILEANALISE << "' não existe" << endl;
        return -1;
    }

    if (excluirManterControle == 1 && Util::file_exists(FILECONTROLPATH))
    {
        Util::removeFile(FILECONTROLPATH);
        cout << "O arquivo de controle '" << FILECONTROLPATH << "' foi removido" << endl;
    }

    cout << "Análise do arquivo '" << FILEANALISE << "'" << endl;

    return 0;
}

int main(int argc, char **argv)
{
    if (initial(argc, argv) < 0)
    {
        return -1;
    }
    findPalindrome();
    return 0;
}