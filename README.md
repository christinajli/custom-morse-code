# custom-morse-code

Morse code, is designed such that the most frequently used letters have the shortest code. However, as many has pointed out, the ordering of such character frequencies based on common English text in the newspaper is not the most efficient. New frequency orders have been proposed, for example those based on Google Book's data and words in the Oxford Dictionary. 

The International Morse Code ordering is roughly "etianmsurwdkgohvf-l,pjbxcyzq.&nbsp;&nbsp;54 3&nbsp;&nbsp;2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;16&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7&nbsp;&nbsp;&nbsp;8 90". Spaces are used to denote skipped codes.

<p align="center">
    <img src="readme-imgs/international-morse.png" />
</p>


The goal of this project is to take in any ordering of character frequency (and any characters, numbers, punctuations), and design a translator to encode and decode text to custom binary code.

## Algorithm
Creating the encodings is similar to building up a binary tree given the breath-first search traversal, or the level order traversal, of the nodes/characters. Moving to the left sub tree is denoted with a dot ".", and moving to the right sub tree is a dash "-". 

For example, given the custom ordering of letters "abcdwxyz", "a" is encoded as ".", "b" is encoded as "-", "d" is encoded as ".-", "z" is encoded as "..-" etc. For this encoding, "bad" is "- . .-", but if decoded with International Morse Code, it will read "tea".

<p align="center">
    <img src="readme-imgs/custom-morse.png" />
</p>

The algorithm will only encode and decode the letters provided, any unknow characters will be translated to "?". 

### Usage
1. ```git clone``` the repository, and ```cd``` to directory
2. ```make output```
3. ```./output```
4. follow prompt from command line, and input custom ordering of letters
5. use "encode" or "decode" keywords followed by text or code to translate

## Opens
- [ ] command line interface 
- [ ] edge cases: check each letter provided in ordering is unique
- [ ] edge cases: tree root is set to `*` as placeholder, encoded characters cannot include `*`

## References 

* [Morse Code applications](https://eclecticlight.co/2015/10/20/the-code-lives-on-how-morse-is-still-not-dead/)
* [Alternate Morse Codes](https://eclecticlight.co/2015/10/22/reinventing-morse-code-using-modern-theory/)
* [ITU Morse Code Standards](https://www.itu.int/dms_pubrec/itu-r/rec/m/R-REC-M.1677-1-200910-I!!PDF-E.pdf)
* [Letter frequency based on Google Book's data](http://norvig.com/mayzner.html)
* [Letter frequency based on Oxford Dictionary](https://www3.nd.edu/~busiforc/handouts/cryptography/letterfrequencies.html)