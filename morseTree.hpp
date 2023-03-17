#ifndef MORSETREE_H
#define MORSETREE_H

#include <iostream>
using namespace std;

class treeNode {
public:
    treeNode(char data) :
        character(data),
        code(""),
        leftNode(nullptr),
        rightNode(nullptr){};
    
    void addCode(string data) { code = data; };

    char character;
    string code;
    treeNode* leftNode;
    treeNode* rightNode;
};

class morseTree {
public:
    morseTree();

    /**
     * Creates a binary tree
     *
     * @param order level order traversal string
     */
    void buildTree(string order);

    void printTree();
    treeNode* getRoot();
    // string getCode(char data); 
    // char decode(string code);

private: 
    treeNode* root;
};

#endif // MORSETREE_H