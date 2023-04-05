#include <iostream>
#include <assert.h>
#include "morseTree.hpp"
using namespace std;

void test_buildTree() {
    string order = "abcdefg";
    cout << "Testing  buildTree() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);
    treeNode* n = tree.getRoot();

    assert(n->character == '*');

    assert(n->leftNode->character == 'a');
    assert(n->leftNode->code == ".");

    assert(n->rightNode->character == 'b');
    assert(n->rightNode->code == "-");

    assert(n->leftNode->leftNode->leftNode->character == 'g');
    assert(n->leftNode->leftNode->leftNode->code == "...");

    cout << "\t buildTree() tests passed" << endl;
    cout << endl;
}

void test_decode() {
    string order = "mnopqrstuv";
    cout << "Testing  getChar() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);

    assert(tree.getChar(".") == 'm');
    assert(tree.getChar("-") == 'n');

    assert(tree.getChar("..") == 'o');
    assert(tree.getChar("--") == 'r');

    assert(tree.getChar("--.") == '\0');
    assert(tree.getChar("---") == '\0');

    cout << "\t getChar() tests passed" << endl;
    cout << endl;
}

void test_getCode() {
    string order = "wxyz123";
    cout << "Testing  test_getCode() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);

    assert(tree.getCode('w') == ".");
    assert(tree.getCode('x') == "-");

    assert(tree.getCode('1') == "-.");
    assert(tree.getCode('2') == "--");

    assert(tree.getCode('4') == "?");
    assert(tree.getCode('5') == "?");

    cout << "\t test_getCode() tests passed" << endl;
    cout << endl;
}

int main(int argc, char** argv) {
    cout << "Running unit tests for morseTree class" << endl;
    cout << endl;

    test_buildTree();
    test_decode();
    test_getCode();

    return 0;
}
