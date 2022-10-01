#ifndef MEMINFO_H
#define MEMINFO_H

#include <string>
#include <fstream>
#include <limits>

// https://stackoverflow.com/questions/349889/how-do-you-determine-the-amount-of-linux-system-ram-in-c
class MemInfo
{
private:
    std::ifstream file;

    unsigned long get_mem_info(std::string tokenParam = "MemTotal:")
    {
        if (!file.is_open())
        {
            open_file();
        }
        if (!file.is_open())
        {
            return -1;
        }

        file.seekg(0, file.beg); // início arquivo
        std::string token;
        while (file >> token)
        {
            if (token == tokenParam)
            {
                unsigned long mem;
                return file >> mem ? mem : 0;
            }
            // Ignore the rest of the line
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return 0; // Nothing found
    };

public:
    MemInfo() { open_file(); }

    void open_file() { file.open("/proc/meminfo"); }
    void close_file() { file.close(); }

    unsigned long getMemoriaTotal()
    {
        return get_mem_info("MemTotal:");
    };

    unsigned long getMemoriaDisponivel()
    {
        return get_mem_info("MemAvailable:");
    };

    double porcentagemMemoriaLivre()
    {
        return (100.0 * getMemoriaDisponivel()) / getMemoriaTotal();
    }

    // limiar % de memória livre aceita
    int limiarAceito(double limiar = 20.0)
    {
        return (porcentagemMemoriaLivre() >= limiar) ? 1 : 0;
    }
};

#endif