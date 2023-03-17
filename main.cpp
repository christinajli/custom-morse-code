#include<iostream>
using namespace std;

// space between two letters
const int letter_space = 1;
// space between two words
const int word_space = 3;
// unsupported characters
const string unsupported = "?";
// morse code encodings of lower case characters 
const string encodings[]={".-", "-...", "-.-", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

string encode(string text) {
    string code;
    for(char c : text) {
        if (c == ' ') {
            string spaces(word_space - letter_space, ' ');
            code += spaces;
        } else if (islower(c)){
            // ascii to zero based index 
            code += encodings[int(c) - int('a')];
            string spaces(letter_space, ' ');
            code += spaces;
        } else {
            code += unsupported;
        }
    }
    return code; 
}

char decode_letter(string letter_code) {
    int i = 0;
    // O(n)
    for (; i < sizeof(encodings)/sizeof(encodings[0]); i++) {
        if (encodings[i] == letter_code) {
            break;
        }
    }
    return char(i + 'a');
}

string decode(const string code) {
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
    if (!letter.empty()){
        text += decode_letter(letter);
    }
    return text;
}

int main(int argc, char** argv) {
    cout << encode("hello world") << endl;
    cout << decode(".... --- .--   .- .-. .   -.-- --- ..-") << endl;
    cout << decode(encode("bye bye")) << endl;
    return 0;
}