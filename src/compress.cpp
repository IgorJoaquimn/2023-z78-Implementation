#include "z78.h"


void clean_output(std::string file, Trie &t, int count)
{
    std::ifstream aux_file;
    aux_file.open(aux_filename, std::ios_base::binary);

    std::ofstream output;
    output.open(file, std::ios_base::binary);

    uint32_t n_byte = ceil(ceil(log2(count)) / 8);
    output.write(reinterpret_cast<char *>(&n_byte), sizeof(uint32_t));

    char c;
    uint64_t a;
    while (aux_file.read(reinterpret_cast<char *>(&a), sizeof(a)))
    {
        aux_file.read(reinterpret_cast<char *>(&c), sizeof(c));

        output.write(reinterpret_cast<char *>(&a), n_byte);
        output.write(reinterpret_cast<char *>(&c), sizeof(c));
    }

    aux_file.close();
    output.close();
}

int compress(int argc, char *argv[])
{
    std::string input_name = argv[2];
    std::ifstream input;
    input.open(input_name);

    std::ofstream aux_file;
    aux_file.open(aux_filename, std::ios_base::binary);

    Trie t;
    char c;
    bool exist = 0;
    Node *element = nullptr;

    std::string s = "";
    std::string residual = "";
    t.add(s);

    uint64_t count = 0;
    while (input.get(c))
    {
        s.push_back(c);
        std::tie(element, exist) = t.search(s, element);
        if (exist == 0)
        {
            aux_file.write(reinterpret_cast<const char *>(&element->cod), sizeof(uint64_t));
            aux_file.write(&c, sizeof(char));

            t.add(s, element);
            element = nullptr;
            s = "";
            residual = "";
            count++;
        }
        else
        {
            residual += s;
            s = "";
        }
    }
    if (exist)
    {
        residual.pop_back();
        std::tie(element, exist) = t.search(residual);
        aux_file.write(reinterpret_cast<const char *>(&element->cod), sizeof(uint64_t));
        aux_file.write(&c, sizeof(char));
        t.add(s);
        s = "";
        count++;
    }
    input.close();
    aux_file.close();
    std::string file = input_name.substr(0, input_name.size()-4) + ".z78";
    if(argc == 4) file = argv[3];
    clean_output(file, t, count);
    return 0;
}
