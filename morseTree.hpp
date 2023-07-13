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
    
    ~treeNode();
    void addCode(string data) { code = data; };

    char character;
    string code;
    treeNode* leftNode;
    treeNode* rightNode;
};

class morseTree {
public:
    morseTree();
    ~morseTree();

    /**
     * Creates a binary tree
     *
     * @param order: level order traversal string
     */
    void buildTree(string& order);

    /**
     * Finds and returns the morse code of a given character by breadth first search 
     *
     * @param data: character
     * @returns code: the string of morse code associated with the given character
     */
    string getCode(char data);

    /**
     * Finds and returns the character of a given code by traversing the tree
     *
     * @param code: morse code string
     * @returns character: the character associated with the given code
     */
    char getChar(string code);

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