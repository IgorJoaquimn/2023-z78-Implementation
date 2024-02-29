# TP1-Algorithms-2-z78
## The report is present in the file "Practical Work 1 Algorithms 2.pdf"
## The test files are in the "test_files" folder
Practical Work 1
DCC216 - Algorithms
Igor Joaquim da Silva Costa

## 1. Introduction
The proposed problem was to implement the LZ78 algorithm for text compression with the help of a trie tree.
The LZ78 compression algorithm is a method that seeks to replace sequences of repeated characters in a text with codes that represent these sequences, with the aim of reducing the size of the original file. It works in linear time in relation to the size of the input file, being efficient for compressing large corpuses where sequences have a similar structure.
To implement it, it is necessary to use a dictionary that allows many searches and data insertions to be carried out. In this sense, the Trie tree emerges as an efficient data structure for implementing the algorithm. This work aims to implement the LZ78 algorithm using the Trie tree as a dictionary. Furthermore, we seek to understand how the LZ78 implementation can be used as a basis for other compression algorithms currently available.
In view of the above, the present documentation aims to detail how the system was modeled (Section 2), how it was implemented (Section 3) and its strengths and limitations (Section 4). Finally, the project is summarized together with the learning generated during the production of the work (Section 5). (Section 6) summarizes the compilation and execution information.

## 6. Instructions for compilation and execution:
6.1 Compilation
There are parts of the program that are only compatible with the most recent versions of the c++ language, that said, the following configurations must be followed for compilation:

Language: C++
Compiler: Gnu g++
Compilation flags: -std=c++17 -g
Language version: standard C++17
Operating system (preference): distributions based on the Linux 5.15 kernel.

The command to automatically compile the program is present in the “Makefile” file and its execution is called by the “make all” command. This way, the “tp1” executable will be compiled and ready to be used.
6.2 Execution
Here are the instructions for manual execution:

Make sure that the compilation was generated correctly, if any problems occur, run the “make all” command present in the “Makefile”.

Once the previous steps have been completed, run the program with the command:
Compression:
/bin/tp1.out -c <input_file> [-o <output_file>]
Decompression
./bin/tp1.out -x <input_file> [-o <output_file>]

The output will be printed to the output_file.
