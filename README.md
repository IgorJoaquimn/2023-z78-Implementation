# TP1-Algoritmos-2-z78
## O relatório está presente no arquivo "Trabalho Prático 1 Algoritmos 2.pdf"
Trabalho Prático 1
DCC216 - Algoritmos 
Igor Joaquim da Silva Costa

## 1. Introdução
O problema proposto foi implementar o algoritmo LZ78 para compressão de texto com o auxílio de uma árvore trie. 
O algoritmo de compressão LZ78 é um método que busca substituir as sequências de caracteres repetidos em um texto por códigos que representam essas sequências, com o objetivo de reduzir o tamanho do arquivo original. Ele funciona em tempo linear em relação ao tamanho do arquivo de entrada, sendo eficiente para comprimir grandes córpus onde as sequências possuem estrutura parecida.
Para implementá-lo, é necessário utilizar um dicionário que possibilite a realização de muitas buscas e inserções de dados. Nesse sentido, a árvore Trie surge como uma estrutura de dados eficiente para a implementação do algoritmo. Este trabalho tem como objetivo a implementação do algoritmo LZ78 utilizando a árvore Trie como dicionário. Além disso, busca-se entender como a implementação do LZ78 pode ser utilizada como base para outros algoritmos de compressão atualmente disponíveis.
Diante do exposto, a documentação presente possui como objetivo detalhar como o sistema foi modelado (Seção 2), como ele foi implementado (Seção 3) e quais seus pontos fortes e limitações (Seção 4). Por fim, o projeto é sumarizado junto com os aprendizados gerados durante a produção do trabalho(Seção 5). A (Seção 6) sumariza as informações de compilação e execução.

## 6. Instruções para compilação e execução:
6.1 Compilação
	Existem partes do programa que são compatíveis apenas às versões mais recentes da linguagem c++, dito isso, deve-se seguir as seguintes configurações para a compilação:

Linguagem: C++
Compilador: Gnu g++
Flags de compilação: -std=c++17 -g
Versão da linguagem: standard C++17
Sistema operacional (preferência): distribuições baseadas no kernel Linux 5.15.

O comando para compilar o programa automaticamente está presente no arquivo “Makefile” e sua execução é chamada pelo comando “make all”. Deste modo, o executável “tp1” estará compilado e pronto para ser utilizado.
6.2 Execução
	Seguem as instruções para a execução manual:

Certifique-se que o compilável foi gerado de maneira correta, se algum problema ocorrer, execute o comando “make all” presente no “Makefile”.

Uma vez que os passos anteriores foram cumpridos, execute o programa com o comando:	
Compressão:
/bin/tp1.out -c <arquivo_entrada> [-o <arquivo_saida>]
Descompressão
./bin/tp1.out -x <arquivo_entrada> [-o <arquivo_saida>]

A saída será impressa no arquivo_saida.
