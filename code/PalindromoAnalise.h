#ifndef PALINDROMOANALISE_H
#define PALINDROMOANALISE_H

#include <string>
#include <fstream>
#include <limits>

#include "SalvarControle.h"
#include "Util.h"
#include "MemInfo.h"

#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

class PalindromoAnalise
{
private:
    Arquivos arq;
    SalvarControle ctrl;
    const int limiar_save_ctrl = 100000;
    const int limiar_analise_mem = 2000000;

    int ispalidromerecur(int posInitial, int posFinal)
    {
        if (posInitial == posFinal || posInitial > posFinal)
        {
            return 1;
        }

        char *v1 = arq.readPos(posInitial);
        char *v2 = arq.readPos(posFinal); // strcmp = 0 - iguais
        bool comparacao = strcmp(v1, v2) == 0;
        delete v1, v2;
        return comparacao ? ispalidromerecur(posInitial + 1, posFinal - 1) : 0;
    }

public:
    PalindromoAnalise(const std::string FILEPATH, const std::string FILECONTROLPATH, bool limparControle)
    {
        if (limparControle)
        {
            Util::removeFile(FILECONTROLPATH);
        }

        arq.open_file(FILEPATH);
        ctrl.setFileControlPath(FILECONTROLPATH);
    }

    Palindrome ispalidrome(int sizeSearch = 3, bool analisarMemoria = true)
    {
        if (sizeSearch <= 0)
        {
            sizeSearch = 1;
        }
        int firstPos = 0;
        Palindrome controle = ctrl.getControl();
        if (controle.is >= 0)
        {
            firstPos = controle.start;
        }
        std::cout << "firstPos: " << firstPos << std::endl;

        Palindrome rt(0);
        int length = arq.fileLength();

        int start = firstPos;
        int end = start + (sizeSearch - 1);

        // cout << "length: " << length << endl;
        if (end > length)
        {
            arq.close();
            return rt;
        }

        int rtAux = 0;
        do
        {
            rtAux = ispalidromerecur(start, end);

            if (rtAux == 1)
            {
                char *valorStr = arq.readString(start, end);

                // controle
                ctrl.saveControl(0, start, end, valorStr);

                if (Util::isPrime(valorStr) == 0)
                {
                    delete valorStr;
                    rtAux = 0; // não é primo
                    start++;
                    end++;
                    if (end > length)
                    {
                        arq.close();
                        return rt;
                    }
                    continue;
                }
                else
                {
                    rt.is = 1;
                    rt.start = start;
                    rt.end = end;
                    strcpy(rt.valor, valorStr);

                    ctrl.saveControl(rt);

                    arq.close();

                    delete valorStr;
                    return rt;
                }
                // cout << valorStr << ", prime: " << isPrime(valorStr) << endl;
                delete valorStr;
            }

            if (start % limiar_save_ctrl == 0)
            {
                ctrl.saveControl(0, start, end, arq.readString(start, end));
                // cout << "controle salvo: " << start << endl;
            }

            if (analisarMemoria && start % limiar_analise_mem == 0)
            {
                unsigned long memoriaDisponivel = MemInfo::getMemoriaDisponivel();
                std::cout << "Análise de memória, disponível: " << memoriaDisponivel;
                std::cout << " [" << start << ", " << end << "]" << std::endl;

                if (MemInfo::limiarAceito(40.0) == 0)
                {
                    std::cout << "Waiting 10s" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(10));
                }

                if (MemInfo::limiarAceito() == 0)
                {
                    std::cout << "--- Limiar de memória disponível (" << memoriaDisponivel << ") ultrapassado ---" << std::endl;
                    ctrl.saveControl(0, start, end, arq.readString(start, end));
                    arq.close();
                    return rt;
                }
            }

            start++;
            end++;
            // cout << start << ", " << end << ", valorStr: " << readString(file, start, end) << endl;
            if (end > length)
            {
                arq.close();
                return rt;
            }
        } while (rtAux == 0);

        arq.close();
        return rt;
    }
};

#endif