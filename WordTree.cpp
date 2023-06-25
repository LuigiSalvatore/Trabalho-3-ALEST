#include "WordTree.hpp"
#include <sstream>
// #define DEBUG

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
CharNode *WordTree::findCharNodeForWord(string word)
{
    list<CharNode *> nodo;                         // lista de nodo
    int count = 0;                                 // count pra fazer o loop
    while (count < word.size())                    //
    {                                              // enquanto a palavra não acabou
        char letra = word[count];                  // char letra = char na posicao count da palavra
        CharNode *aux = aux->findChildChar(letra); // nodo aux = nodo na posicao do char letra
        nodo.push_back(aux);                       // insere o nodo na lista de char nodo
        count++;                                   // incrementa o count (vai pra proxima letra)
    }                                              //
    CharNode *send = nodo.back();                  //
    nodo.clear();                                  //
    return send;                                   // retorna o ultimo nodo inserido na lista (a ultima letra de count)
}
/* list<Palavra> WordTree::searchAll(string prefix)
{
    list<CharNode *> auxList;
    list<Palavra> result;
    string auxString;
    result.clear();
    auxList = root->subtrees;
    while (auxList.size() > 0)
    {
        CharNode *auxChar = auxList.front();
        for (char letra : prefix)
        {
            if (auxChar->character == letra || auxChar->character + 32 == letra)
            {
                if (auxChar->significado == "")
                {
                    auxString += auxChar->character;
                    auxList = auxChar->subtrees;
                    cout << "entrei no primeiro if" << endl;
                }
                if (auxChar->significado != "")
                {
                    auxString += auxChar->character;
                    Palavra pal(auxString, auxChar->significado);
                    result.push_back(pal);
                    auxList = auxChar->subtrees;
                    cout << "entrei no segundo if" << endl;
                }
            }
        }
        auxList.pop_front();
    }
    return result;
} */
list<string> WordTree::searchAll(string prefix)
{
    list<string> words;                          // List of words that can be formed with the prefix that will be returned
    CharNode *aux = findCharNodeForWord(prefix); // Find the node that forms the prefix
    if (aux->getSubtreesSize() > 0 && aux != root)
    {
        list<CharNode *> iteratorExorcisado = aux->subtrees; // <--- contribuições para o exorcismo/purgação do iterator k
        int size = iteratorExorcisado.size();
        for (int i = 0; i < size; i++)
        { // For each subtree of the node that forms the prefix
            iteratorExorcisado.pop_front();
        }
        iteratorExorcisado = aux->subtrees;
        size = iteratorExorcisado.size();
        for (int i = 0; i < size; i++)
        { // For each subtree of the node that forms the prefix
            CharNode *temp = iteratorExorcisado.front();
            iteratorExorcisado.pop_front();
            if (temp->significado != "")
            {
                words.push_back(temp->getWord()); // If the node has a signature, add the word to the list
            }
            if (temp->getSubtreesSize() == 0)
            {
                continue; // If the subtree is empty, continue
            }
            else
            {                                                      // If the subtree is not empty
                list<string> auxList = searchAll(temp->getWord()); // Recursively search for more words
                words.splice(words.end(), auxList);                // Add the words found to the list
            }
        }
    }
    return words;
}

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