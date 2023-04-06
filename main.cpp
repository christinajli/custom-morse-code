#include<iostream>
#include "morseTree.hpp"
#include "translate.hpp"
using namespace std;
using namespace translate;

int main(int argc, char** argv) {

    string order = "abcdefghijklmnopqrstuvwxyz";
    cout << "Testing  main() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);

    cout << encode(tree, "hello world") << endl;
    cout << decode(tree, "..- .... -...   . ..-- -.   -.-. .... .--.") << endl;
    cout << decode(tree, encode(tree,"bye bye")) << endl;

    return 0;
}