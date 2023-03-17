#ifndef MORSETREE_H
#define MORSETREE_H

#include <iostream>
using namespace std;

class treeNode {
public:
    treeNode(char data, treeNode* left = nullptr, treeNode* right = nullptr) :
        character(data),
        leftNode(left),
        rightNode(right){};

    char character;
    treeNode* leftNode;
    treeNode* rightNode;
};

class morseTree {
public:
    morseTree() : root(nullptr) {};
    morseTree(treeNode* node) : root(node) {};

    /**
     * Creates a binary tree
     *
     * @param order level order traversal string
     */
    void buildTree(string order);

    void printTree();
    // string getCode(char data); 
    // char decode(string code);

private: 
    treeNode* root;
};

#endif // MORSETREE_H