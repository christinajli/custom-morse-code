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
     * @param order: level order traversal string
     */
    void buildTree(string order);

    // string getCode(char data);

    /**
     * Finds and returns the character of a given code
     *
     * @param code: morse code string
     * @returns character: the character associated with the given code
     */
    char decode(string code);

    /**
     * Helper method to view tree in level order, and print out character and the code
     *
     */
    void printTree();
    /**
     * Helper method to get tree root
     *
     * @returns root
     */
    treeNode* getRoot();

private: 
    treeNode* root;
};

#endif // MORSETREE_H