#include<iostream>
using namespace std;

// space between two letters
const string letter_space = " ";
// space between two words
const string word_space = "   ";
// unsupported characters
const string unsupported = "?";
// morse code encodings of lower case characters 
const string encodings[]={".-", "-...", "-.-", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

string encode(string text) {
    string code;
    for(char c : text) {
        if (c == ' ') {
            code += word_space;
        } else if (islower(c)){
            // ascii to zero based index 
            code += encodings[int(c) - int('a')];
            code += letter_space;
        } else {
            code += unsupported;
        }
    }
    return code; 
}

char decode_letter(string letter_code) {
    int i = 0;
    // O(n)
    for (i; i < sizeof(encodings)/sizeof(encodings[0]); i++) {
        if (encodings[i] == letter_code) {
            break;
        }
    }
    return char(i + 'a');
}

string decode(string code) {
    string text;
    string letter;
    bool prev_space = false;
    const char* code_ptr = code.c_str();

    while (*code_ptr != '\0') {
        if (*code_ptr == ' ') {
            if (prev_space) {
                text += " ";
                prev_space = false;
                code_ptr++;
                code_ptr++;
            } else {
                text += decode_letter(letter);
                letter = "";
                prev_space = true;
            }
        } else {
            letter += *code_ptr;
            prev_space = false;
        }
        code_ptr++;
    }
    text += decode_letter(letter);
    return text;
}

int main(int argc, char** argv) {
    cout << encode("hello world") << endl;
    cout << decode(".... --- .--    .- .-. .    -.-- --- ..-") << endl;
    return 0;
}