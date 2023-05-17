// The Manager file for the Assignment 1: Word Search
// Created by Lucas Lassila on 5/15/23.
//

#ifndef ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
#define ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
// methods defined here
#include <iostream>
#include <random>
#include<cstdlib>

using namespace std;

class Manager {
public:
    // constructor, value initialization of array word[]

        string word[4] = {"CAR", "VOLVO", "BOAT", "BIKE"};// array that can hold four words
        //char matrix[6][6] ;

};

class WordSearch : public Manager{ // inherit the arrays from manager
    public:
    int loc = 0; // int to help store location of common values
    int m=6, n=6 ;// dimensions for matrix
    int matrix [6][6] = {};




    void matrixToZero(){ // fill array with stars
        for(int i = 0; i<m; i++){
            for (int j = 0; j <= 5; j++) {
                matrix[i][j] = 0 ;
            }
        }

    }


     void getWords(){ // method to put users word choice into word[]
        cout<< "please enter a 2 - 6 letter word when prompted"<< endl;
        cout<< "these will be the words in the word search"<< endl;
        for(int i = 0; i<= 3; i++){
            cout<< "enter a word"<< endl;
            cin >> word[i];
        }

    }

    void arrange(){
// j is columns, i is row
         for(int i = 0; i < 4; i++){
             string temp = word[i];
             for (int j = 0; j< temp.size(); j++){ // want to put each letter into a spot in matrix
                 matrix[i][j] = temp.at(j) - 0; // add ascii value into matrix
                 //cout<< matrix[i][j] <<"";
             }
             //cout<<endl;
         }
     }// end arrange


    void randFill(){
        srand(unsigned (1));
        //cout<< random;
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(matrix[i][j] == 0){
                    int random = 65 + (rand() % 24); // new random number between 65 & 99
                    matrix[i][j] = random ;
                }else{
                    // do nothing
                }   // end if else
            }// end inner for

        }// end outer for
    }// end rand fill

     void wordSearchOut(){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = matrix[i][j];
                cout << ch ;
                }
                cout <<endl;
            }
    }// end print Matrix

    void print(){ // method to test word[] by printing it to console
        for(string val : word){
            cout<< val << endl;
        }

    }



};
#endif //ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
