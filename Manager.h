// The Manager file for the Assignment 1: Word Search
// Created by Lucas Lassila on 5/15/23.
//

#ifndef ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
#define ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
// methods defined here
#include <iostream>

using namespace std;

class Manager {
public:
    // constructor, value initialization of array word[]

        string word[4] = {};
        char matrix[6][6] = {}; // array that can hold four words

};

class WordSearch : public Manager{ // inherit the arrays from manager
    public:

     void getWords(){
        cout<< "please enter a 2 - 6 letter word when prompted"<< endl;
        cout<< "these will be the words in the word search"<< endl;
        for(int i = 0; i<= sizeof(word); i++){
            cout<< "enter a word"<< endl;
            cin >> word[i];
        }
    }

    void print(){
        for(string val : word){
            cout<< val << endl;
        }
    }



};
#endif //ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
