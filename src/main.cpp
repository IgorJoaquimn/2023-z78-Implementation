#include "z78.h"

int main(int argc, char *argv[])
{
    std::string comp = "-c";
    std::string dcomp = "-x";
    if (argv[1] == comp)
        return compress(argc, argv);
    if (argv[1] == dcomp)
    {
        return decompress(argc, argv);
    }
    else
    {
        throw std::invalid_argument("Não especificada a compressão ou descompressão");
        return -1;
    }
}
