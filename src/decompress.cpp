#include "z78.h"

int decompress(int argc, char *argv[]) 
{
    std::string input_name = argv[2];
    std::ifstream input;
    input.open(input_name,std::ios_base::binary);

    std::string output_name = input_name.substr(0, input_name.size()-4) + ".txt";
    if(argc == 4) output_name = argv[3];

    std::ofstream output;
    output.open(output_name);

    Trie t;
    std::string s = "";
    t.add(s);
    uint32_t n_byte;
    input.read(reinterpret_cast<char *>(&n_byte), sizeof(uint32_t));
    char c;
    uint32_t i;


    while (input.read(reinterpret_cast<char *>(&i), n_byte) and input.read(reinterpret_cast<char *>(&c), sizeof(c)))
    {
        // unsigned mask = (1 << n_byte*8) - 1;
        // i &= mask;
        Node *element   = t.get_i_node(i);
        std::string a   = element->get_string();
        a.push_back(c);
        t.add(c,element);
        output << a;
    }
    input.close();
    output.close();
    return 0;
}   