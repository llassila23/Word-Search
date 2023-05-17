// The Manager file for the Assignment 1: Word Search
// Created by Lucas Lassila on 5/15/23.
//

#ifndef ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
#define ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
// methods defined here
#include <iostream>
#include <random>

using namespace std;

class Manager {
public:
    // constructor, value initialization of array word[]

        string word[4];
        char matrix[6][6];// array that can hold four words

};

class WordSearch : public Manager{ // inherit the arrays from manager
    public:
        int loc = 0; // int to help store location of common values


     void getWords(){ // method to put users word choice into word[]
        cout<< "please enter a 2 - 6 letter word when prompted"<< endl;
        cout<< "these will be the words in the word search"<< endl;
        for(int i = 0; i<= 3; i++){
            cout<< "enter a word"<< endl;
            cin >> word[i];
        }
    }

    void arrange(){
         int randNum = rand() ;
         cout<< randNum<< endl; // test
// j is columns, i is rows
         for(int i = 0; i < sizeof(word); i++){
             string temp = word[i];
             for (int j = 0; j< temp.size(); j++){ // want to put each letter into a spot in matrix
                 matrix[i][j] = temp.at(j); // advance each row by i,
             }
         }
         printMatrix(); // method to print the nxn matrix array

     }// end arrange
     void printMatrix(){
         cout<< "printing the test WS: \n";
         for (int i = 0; i<6; i++){
             for(int j = 0; j<6; j++){
                 char temp = matrix[i][j];
                 cout<< temp ;
             }
             cout<< "" << endl;
         }

     }

    void print(){ // method to test word[] by printing it to console
        for(string val : word){
            cout<< val << endl;
        }
    }



};
#endif //ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
