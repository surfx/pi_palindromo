#ifndef MEMINFO_H
#define MEMINFO_H

#include <string>
#include <fstream>
#include <limits>

// https://stackoverflow.com/questions/349889/how-do-you-determine-the-amount-of-linux-system-ram-in-c
class MemInfo
{
private:
    static unsigned long get_mem_info(std::string tokenParam = "MemTotal:")
    {
        std::string token;
        std::ifstream file("/proc/meminfo");
        while (file >> token)
        {
            if (token == tokenParam)
            {
                unsigned long mem;
                if (file >> mem)
                {
                    return mem;
                }
                else
                {
                    return 0;
                }
            }
            // Ignore the rest of the line
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return 0; // Nothing found
    };

public:
    static unsigned long getMemoriaTotal()
    {
        return get_mem_info("MemTotal:");
    };

    static unsigned long getMemoriaDisponivel()
    {
        return get_mem_info("MemAvailable:");
    };

    static double porcentagemMemoriaLivre()
    {
        return (100.0 * getMemoriaDisponivel()) / getMemoriaTotal();
    }

    // limiar % de memória livre aceita
    static int limiarAceito(double limiar = 20.0)
    {
        return (porcentagemMemoriaLivre() >= limiar) ? 1 : 0;
    }
};

#endif