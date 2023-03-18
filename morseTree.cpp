#include <iostream>
#include <queue>
#include "morseTree.hpp"

using namespace std;

morseTree::morseTree() {
    root = new treeNode('*');
}

treeNode* morseTree::getRoot() {
    return root; 
}

void morseTree::buildTree(string order) {
    queue<treeNode*> nodeQueue;
    nodeQueue.push(root);

    for(char c : order) {
        treeNode* node = new treeNode(c);
        if (nodeQueue.front()->leftNode == nullptr) {
            node->addCode(nodeQueue.front()->code + ".");
            nodeQueue.front()->leftNode = node;
        } else {
            node->addCode(nodeQueue.front()->code + "-");
            nodeQueue.front()->rightNode = node;
            nodeQueue.pop();
        }
        nodeQueue.push(node);
    }
}

void morseTree::printTree() {
    if (root == nullptr) {
        cout << "Empty Tree!" << endl;
        return;
    }

    queue<treeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        cout << nodeQueue.front()->character << ":" << 
            nodeQueue.front()->code << endl;
        if (nodeQueue.front()->leftNode != nullptr) {
            nodeQueue.push(nodeQueue.front()->leftNode);
        }
        if (nodeQueue.front()->rightNode != nullptr) {
            nodeQueue.push(nodeQueue.front()->rightNode);
        }
        nodeQueue.pop();
    }
}

char morseTree::decode(string code) {
    treeNode* current = root;

    for (char c : code) {
        if (c == '.' && current->leftNode != nullptr) {
            current = current->leftNode;
        } else if (c == '-' && current->rightNode != nullptr) {
            current = current->rightNode;
        } else {
            cout<<"Invalid input code or character does not exist" << endl;
            return '\0';
        }
    }

    return current->character;
}