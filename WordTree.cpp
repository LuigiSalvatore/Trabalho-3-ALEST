#include "WordTree.hpp"

//////////////////////////////////
//          WordTree            //
//////////////////////////////////
WordTree::WordTree()
{
    root = new CharNode(' ', "");
    totalNodes = 1;
    totalWords = 0;
}
int WordTree::getTotalWords() { return totalWords; }
int WordTree::getTotalNodes() { return totalNodes; }
void WordTree::addWord(string word, string significado) {}
CharNode WordTree::findCharNodeForWord(string word) {}
list<string> WordTree::searchAll(string prefix) {}

//////////////////////////////////
//          CharNode            //
//////////////////////////////////
CharNode::CharNode(char element, string significado)
{
    father = NULL;
    character = element;
    this->significado = significado;
}
CharNode CharNode::addChild(char element, string significado)
{
    if (findChildChar(element) != nullptr)
        ;
}
int CharNode::getSubtreesSize() {}
CharNode *CharNode::getSubtree(int idx) {}
string CharNode::getWord() {}
CharNode *CharNode::findChildChar(char element)
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