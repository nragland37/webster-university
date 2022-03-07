//****************************************************************************************************
// 		    File:                 assignment_6.1.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #6
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  March 7, 2022
//
//****************************************************************************************************

#include <iostream>

using namespace std;

int numberWords(const char* words, int size);

//****************************************************************************************************

int main() {
    const int SIZE = 50;
    int result,
        numInput = 3;

    char* words = new char[SIZE];

    for (int i = 0; i < numInput; ++i) {
        cout << "Enter a line of words (less than 50 characters), ended by '.': " << endl;
        cin.getline(words, SIZE);
        result = numberWords(words, SIZE);
        cout << "Total words: " << result << endl
             << endl;
    }

    delete[] words;
    words = nullptr;

    return 0;
}

//****************************************************************************************************

int numberWords(const char* words, int size) {
    int total = 0;
    bool isLetter = false;

    for (int i = 0; i < size; ++i) {
        if (isalpha(words[i])) {
            isLetter = true;
        } else {
            if (isLetter == true) {
                total++;
                isLetter = false;
            }
        }
        if (words[i] == '.' && words[i + 1] == '\0') {  // stops loop with '.' and followed by null byte [incase titles (mr.,ms.,etc)]
            break;
        }
    }

    return total;
}

/*

Enter a line of words (less than 50 characters), ended by '.': 

Total words: 0

Enter a line of words (less than 50 characters), ended by '.':
This contains a name,address, and phone number.
Total words: 8

Enter a line of words (less than 50 characters), ended by '.':
,,,,,,,This      contains,, a name.             
Total words: 4

//****************************************************************************************************

Enter a line of words (less than 50 characters), ended by '.': 
10192,,!@#$%^ hello. 
Total words: 1

Enter a line of words (less than 50 characters), ended by '.':  // user input titles (mr.,ms.,etc)
Hello, we are Mr. and Mrs. Smith.
Total words: 7

Enter a line of words (less than 50 characters), ended by '.':
,   ,,Hello, we,,, are Mr. and Mrs. Smith.
Total words: 7

*/