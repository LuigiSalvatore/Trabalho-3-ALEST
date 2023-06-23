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
int WordTree::getTotalWords() { return totalWords; } // feito
int WordTree::getTotalNodes() { return totalNodes; } // feito
void WordTree::addWord(string word, string significado) {}
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
CharNode *CharNode::addChild(char element, string significado)
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
CharNode *CharNode::getSubtree(int idx) {}
string CharNode::getWord() {}
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