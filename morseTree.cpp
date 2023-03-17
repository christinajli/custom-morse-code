#include <iostream>
#include <queue>
#include "morseTree.hpp"

using namespace std;

void morseTree::buildTree(string order) {
    queue<treeNode*> nodeQueue;

    for(char c : order) {
        treeNode* node = new treeNode(c);
        if (root == nullptr) {
            root = node;
        } else if (nodeQueue.front()->leftNode == nullptr) {
            nodeQueue.front()->leftNode = node;
        } else {
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
        cout << nodeQueue.front()->character << " " << endl;
        if (nodeQueue.front()->leftNode != nullptr) {
            nodeQueue.push(nodeQueue.front()->leftNode);
        }
        if (nodeQueue.front()->rightNode != nullptr) {
            nodeQueue.push(nodeQueue.front()->rightNode);
        }
        nodeQueue.pop();
    }
}