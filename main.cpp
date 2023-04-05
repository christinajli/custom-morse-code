#include<iostream>
#include "morseTree.hpp"
using namespace std;

// space between two letters
const int letter_space = 1;
// space between two words
const int word_space = 3;
// unsupported characters
const string unsupported = "?";

string encode(morseTree& tree, string text) {
    string code;
    for(char c : text) {
        if (c == ' ') {
            string spaces(word_space - letter_space, ' ');
            code += spaces;
        } else if (islower(c)){
            code += tree.getCode(c);
            string spaces(letter_space, ' ');
            code += spaces;
        } else {
            code += unsupported;
        }
    }
    return code; 
}

string decode(morseTree& tree, const string code) {
    string text;
    string letter;
    bool prev_space = false;
    const char* code_ptr = code.c_str();

    while (*code_ptr != '\0') {
        if (*code_ptr == ' ') {
            if (prev_space) {
                text += " ";
                prev_space = false;
                code_ptr += word_space - letter_space - letter_space;
            } else {
                text += tree.getChar(letter);
                letter = "";
                prev_space = true;
            }
        } else {
            letter += *code_ptr;
            prev_space = false;
        }
        code_ptr++;
    }
    if (!letter.empty()){
        text += tree.getChar(letter);
    }
    return text;
}

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