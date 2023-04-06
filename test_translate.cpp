#include <iostream>
#include <assert.h>
#include "morseTree.hpp"
#include "translate.hpp"
using namespace std;
using namespace translate;

void test_encode_decode_valid() {
    string order = "abcdefghijklmnopqrstuvwxyz";
    cout << "Testing  encode_valid() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);

    assert( encode(tree, "ocean breeze") == ".... .. -. . ---   - ..-- -. -. -.-- -." );
    assert( encode(tree, "a ray of sunshine") == ".   ..-- . -.-.   .... --   .-.. .--. --- .-.. ..- .-. --- -." );

    assert( decode(tree, "- . .-   . ...- ...- -.- -.") == "bad apple");
    assert( decode(tree, ".-.- .-. --. -.   .-. .-..   --. .... --- -. -.-.") == "time is money" );


    assert( decode(tree, encode(tree,"hello")) == "hello" );
    assert( decode(tree, encode(tree,"bye bye")) == "bye bye" );


    cout << "\t encode_valid() tests passed" << endl;
    cout << endl;
}

void test_encode_invalid() {
    string order = "abcdefg";
    cout << "Testing  encode_invalid() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);

    assert( encode(tree, "bad apples") == "- . .-   . ? ? ? -. ?");
    assert( encode(tree, "chicken wings") == ".. ? ? .. ? -. ?   ? ? ? ... ?");
    assert( encode(tree, "Cute CAT") == "? ? ? -.   ? ? ?");
    assert( encode(tree, "123 &^.-") == "? ? ?   ? ? ? ?");

    cout << "\t encode_invalid() tests passed" << endl;
    cout << endl;
}

void test_decode_invalid() {
    string order = "abcdefg";
    cout << "Testing  decode_invalid() with order: " << order << endl;

    morseTree tree;
    tree.buildTree(order);

    assert( decode(tree, "- . .-   . ...- ...- -.- -.") == "bad a???e");
    assert( decode(tree, "- -.- . .. -..   .. . .-.-") == "b?ac? ca?");
    assert( decode(tree, "d$g bar!@") == "??" );
    assert( decode(tree, "d o g   b a r k s") == "??? ?????" );

    cout << "\t test_decode_invalid() tests passed" << endl;
    cout << endl;
}

int main(int argc, char** argv) {
    cout << "Running unit tests for translate methods" << endl;
    cout << endl;

    test_encode_decode_valid();
    test_encode_invalid();
    test_decode_invalid();

    return 0;
}
