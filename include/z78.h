#ifndef COMPRESSION
#define COMPRESSION
#include <iostream>
#include <fstream>
#include <tuple>
#include "trie.h"
#include <bitset>
#include <math.h>


const std::string aux_filename = "aux.z78";
void clean_output(std::string file, Trie &t, int count);
int compress(int argc, char *argv[]);
int decompress(int argc, char *argv[]);


#endif /* COMPRESSION */