#include "WordTree.hpp"
#include <sstream>

//////////////////////////////////
//          WordTree            //
//////////////////////////////////
WordTree::WordTree()
{
    root = new CharNode(' ', "");
    totalNodes = 1;
    totalWords = 0;
}
int WordTree::getTotalWords() { return totalWords; }    // feito
int WordTree::getTotalNodes() { return totalNodes; }    // feito
void WordTree::addWord(string word, string significado) // feito
{
    CharNode *auxChar = root;
    for (char obj : word)
    {
        auxChar->addChild(obj, "");
        if (auxChar->findChildChar(obj) != nullptr)
            auxChar = auxChar->findChildChar(obj);
    }
    auxChar->significado = significado;
}
CharNode WordTree::findCharNodeForWord(string word) {}
list<string> WordTree::searchAll(string prefix) {}

//////////////////////////////////
//          CharNode            //
//////////////////////////////////
CharNode::CharNode(char element, string significado) // feito
{
    father = NULL;
    character = element;
    this->significado = significado;
}
CharNode *CharNode::addChild(char element, string significado) // feito
{
    CharNode *auxCharNode = findChildChar(element);
    if (auxCharNode != nullptr)
    {
        auxCharNode->significado = significado;
        return auxCharNode;
    }

    auxCharNode = new CharNode(element, significado);
    subtrees.push_back(auxCharNode);
    auxCharNode->father = this;
    return auxCharNode;
}
int CharNode::getSubtreesSize() // feito
{
    return (int)subtrees.size();
}
CharNode *CharNode::getSubtree(int idx) // feito
{
    list<CharNode *> aux = subtrees;
    for (int i = 0; i < idx; i++)
    {
        aux.pop_front();
    }
    return aux.front();
}
string CharNode::getWord() // feito
{
    stringstream ss;
    CharNode *auxChar = this;
    list<char> aux;
    aux.clear();
    while (auxChar->character != ' ')
    {
        aux.push_front(auxChar->character);
        auxChar = auxChar->father;
    }
    while (aux.size())
    {
        ss << aux.front();
        aux.pop_front();
    }
    return ss.str();
}
CharNode *CharNode::findChildChar(char element) // feito
{
    list<CharNode *> auxLista = subtrees;
    while (auxLista.size())
    {
        if (element == auxLista.front()->character)
            break;
        auxLista.pop_front();
    }
    if (auxLista.size())
        return auxLista.front();
    return nullptr;
}