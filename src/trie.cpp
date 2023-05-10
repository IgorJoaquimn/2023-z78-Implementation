#include "trie.h"

Trie::Trie() {}
Node::Node() {}

std::pair<Node *, bool> Node::search(std::string &str)
{
    if (str == "")
        return {this, 1};
    for (auto child : this->children)
    {
        if (str[0] == child->pattern)
        {
            std::string str_aux = str.substr(1);
            return child->search(str_aux);
        }
    }
    return {this, 0};
}

Node *Trie::create_node(char pattern, Node *parent)
{
    Node *temp = new Node;
    temp->pattern = pattern;
    temp->cod = this->cod;
    temp->parent = parent;
    if (parent != nullptr)
        parent->children.insert(temp);
    this->cod++;
    this->indexes .push_back(temp);
    return temp;
}

int Trie::add(std::string &pattern, Node *last)
{
    if (this->root == nullptr)
    {
        this->root = create_node(pattern[0], nullptr);
        return this->root->cod;
    }

    if (last != nullptr)
        return create_node(pattern.back(), last)->cod;

    auto res = this->root->search(pattern);
    if (res.second == false)
        return create_node(pattern.back(), res.first)->cod;
    return 0;
}


int Trie::add(char &c,Node * last )
{
    return create_node(c, last)->cod;
}



std::pair<Node *, bool> Trie::search(std::string &pattern, Node *last)
{
    if (this->root == nullptr)
        return {nullptr, 0};

    Node *parent = (last == nullptr) ? this->root : last;
    return parent->search(pattern);
}

Node *Trie::get_i_node(int i)
{
    return indexes [i];
}

std::string Node::get_string()
{
    std::string str = "";
    Node *actual = this;
    while(actual != nullptr)
    {
        str.push_back(actual->pattern);
        actual = actual->parent;
    }
    reverse(str.begin(), str.end()); 
    str.erase(0, 1);
    return str;
}
