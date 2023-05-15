// Programmer: Lucas Lassila
// 05.14.2023
// CS 145
// assignment 1 Word Search
// This program is meant to take words from a user and put them in a word search

#include "Manager.h"
using namespace std;
int main(){
    WordSearch newWS;
    newWS.getWords();
    newWS.print();
}


/* prototyping begins here:
header file with bulk of methods

instructions/menu
 take user input of words. start with 3
 put each word in array list (object?)
 build an 2-dimensional array, nxn of chars.
 arrange words in to this array
    traverse one row. if start character of a string is contained in that row. add that string
    that column
rand num. if A mn = null or other placeholder. fill it with rand char within bounds of alphabet
print
 */