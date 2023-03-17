# custom-morse-code

Morse code, first invented by Samuel Morse, is designed such that the most frequently used letters have the shortest code. However, as many has pointed out, the ordering of such character frequencies based on common English text in the newspaper is not the most efficient. New frequency orders have been proposed, for example those based on Google Book's data and words in the Oxford Dictionary. 

This program is designed to take in any ordering of character frequency (and any characters, numbers, punctuations), and allow you to encode and decode text to your own binary code. For example, the American Morse Code ordering is roughly "etianmsurwdkgohvf l pjbxcyzq &nbsp;54 3 &nbsp;&nbsp;2 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;16 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7 &nbsp;&nbsp;8 90". Use space to denote skipped node of the binary tree.

## Algorithm
Creating the encodings is similar to building up a binary tree given the breath-first search traversal, or the level order traversal, of the nodes/characters. Moving to the left sub tree is a ".", and moving to the right sub tree is a "-". 

## Case Study
Analyze ICAO codes for airports, and determine most frequently used characters.
https://github.com/ip2location/ip2location-iata-icao/blob/master/iata-icao.csv 
New proposed ordering
Compare efficiency, taking into consideration both bit size and spacing/length of signals 

## Opens
- [x] ITU Morse Code encode and decode
- [ ] tree data structure to assign . and - to characters
  - [ ] input custom ordering
- [ ] convert encoding to another data structure for faster lookup
- [ ] use encode and decode with new encodings
  - [x] variable letter and word spacing, not hard coded in decode()
  - [ ] faster search for decoding --> O(logn) if given binary tree
- [ ] command line interface 


## References 
* https://www.itu.int/dms_pubrec/itu-r/rec/m/R-REC-M.1677-1-200910-I!!PDF-E.pdf 
* https://eclecticlight.co/2015/10/20/the-code-lives-on-how-morse-is-still-not-dead/
* https://eclecticlight.co/2015/10/22/reinventing-morse-code-using-modern-theory/
* http://norvig.com/mayzner.html 
* https://www3.nd.edu/~busiforc/handouts/cryptography/letterfrequencies.html 
* https://github.com/soham0-0/Morse-Code-Converter/blob/master/main.cpp