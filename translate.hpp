#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include "morseTree.hpp"
using namespace std;

namespace translate
{
    // space between two letters
    const int letter_space = 1;
    // space between two words
    const int word_space = 3;

    string encode(morseTree &tree, string text)
    {
        string code;
        for (char c : text)
        {
            if (c == ' ')
            {
                string spaces(word_space - letter_space, ' ');
                code += spaces;
            }
            else
            {
                code += tree.getCode(c);
                string spaces(letter_space, ' ');
                code += spaces;
            }
        }

        //remove trailing spaces
        code.erase(std::find_if_not(code.rbegin(), code.rend(), [](char c) { return std::isspace(c); }).base(), code.end());

        return code;
    }

    string decode(morseTree &tree, const string code)
    {
        string text;
        string letter;
        bool prev_space = false;
        const char *code_ptr = code.c_str();

        while (*code_ptr != '\0')
        {
            if (*code_ptr == ' ')
            {
                if (prev_space)
                {
                    text += " ";
                    prev_space = false;
                    code_ptr += word_space - letter_space - letter_space;
                }
                else
                {
                    text += tree.getChar(letter);
                    letter = "";
                    prev_space = true;
                }
            }
            else
            {
                letter += *code_ptr;
                prev_space = false;
            }
            code_ptr++;
        }
        if (!letter.empty())
        {
            text += tree.getChar(letter);
        }
        return text;
    }
}
