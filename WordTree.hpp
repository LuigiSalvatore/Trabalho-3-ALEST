#ifndef _WORD_TREE_
#define _WORD_TREE_

#include <list>
#include "Palavra.hpp"
#include <string>
using namespace std;

class CharNode
{
public:
    CharNode *father;
    list<CharNode *> subtrees;
    char character;
    string significado;

    // Construtor
    CharNode(char element, string significado);
    // Adiciona um filho ao nodo
    CharNode *addChild(char element, string significado);
    // Identifica quantos filhos o nodo possui
    int getSubtreesSize();
    // Acessa o filho número "idx"
    CharNode *getSubtree(int idx);
    // Obtém a palavra correspondente a este nodo, subindo até a raiz da árvore
    string getWord();
    // Encontra e retorna o nodo que tem determinado caracter
    CharNode *findChildChar(char element);
};

class WordTree
{
    CharNode *root;
    int totalNodes = 0;
    int totalWords = 0;

public:
    // constutor
    WordTree();
    int getTotalWords();
    int getTotalNodes();
    // Adiciona palavra na estrutura em árvore
    void addWord(string word, string significado);
    // Vai descendo na árvore até onde conseguir encontrar a palavra
    CharNode *findCharNodeForWord(string word);
    // Percorre a árvore e retorna uma lista com as palavras iniciadas pelo prefixo dado.
    list<string> searchAll(string prefix);
};

#endif