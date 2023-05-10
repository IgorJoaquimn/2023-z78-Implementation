#ifndef TRIE
#define TRIE

#include<set>
#include<vector>
#include <string>
#include <algorithm> 

class Node 
{
    private:
        struct Node_comparator
            {
                bool operator()(const Node* L, const Node* R) const { return (L->pattern <= R->pattern); }
            };
    
    public:
        uint64_t cod;
        char pattern;
        Node * parent = nullptr;
        std::set<Node*, Node_comparator> children; 
        std::pair<Node *, bool> search(std::string &str);
        std::string get_string();
        Node();
};

class Trie
{
    private:
        uint64_t cod = 0;
        std::vector<Node *> indexes ;
        Node *create_node(char pattern,Node * parent = nullptr);
        Node *root = nullptr;
    public:
        Trie();
        int add(std::string &str,Node * last = nullptr);
        int add(char &str,Node * last );
        std::pair<Node *,bool> search(std::string &str, Node * last = nullptr);
        Node *get_i_node(int i);

};
#endif