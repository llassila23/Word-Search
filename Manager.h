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

        string word[4] = {"car", "apple", "volvo", "bob"};// array that can hold four words
        int matrix [10][10] = {};
        int location[2] = {0,0};

};

class WordSearch : public Manager{ // inherit the arrays from manager
    public:
    int loc = 0; // int to help store location of common values
    int m=10, n=10 ;// dimensions for matrix
    int wordSize = 4;

    
    void matrixToZero(){ // fill array with empty spaces
        for(int i = 0; i<m; i++){
            for (int j = 0; j <= n; j++) {
                matrix[i][j] = 32; // ascii value of a empty space
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
    void newArrange() { // calls compare, meant to arrange words, references location[]
        bool common = false; // does the next word have a common letter?
        for (int i = 0; i < wordSize; i++) { // to get word
                string wordOne = word[i];
                int spacer = m - wordOne.size(); // spacer to offset from position zero
                spacer = spacer % 2;
            while(!common) { // if common is not true, print horizontal
                int row = 0;
                int letterLoc = 0; // for advancing wordOne.at
                for (int column = 0; column < wordOne.size(); column++) {
                    matrix[row][column + spacer] = wordOne.at(letterLoc) - 0;
                    letterLoc++;
                }
                   common = compare(i, common); // search next word for common letter
            }// end while

            if (common) {// match found
                string wordTwo = word[i+1];
                for (int row = 0; row <= m; row++){ // to search for row location
                    for (int column = 0; column <= n; column++) { // for loop to search for column location
                        char cSearch = matrix[row][column]; // set char = to value
                            if (cSearch == wordOne.at(location[0])){ // if this location = the found common letter
                                while (row + 1 <= wordTwo.size() && location[1] < wordTwo.size()) { // print while in ranges
                                    matrix[row][column] = wordTwo.at(location[1] ) - 0; // set that column to word Two
                                    row += 1;  // advance row
                                    location[1] ++; // advance the value, to traverse through the word
                                }// end while
                            } // end if cSearch
                    }// end for column

                }// end for row

            }// end while common is found
        }// end main for
    } // end newArrange


    bool compare(int i, bool common ){ // set value of location, common letter coordinates

        while((i+1) <= wordSize) { // keep in bounds
            int j = 0;
            char cTwo = word[i + 1].at(j);
            // want to compare first letter of second word with any letter in first word
        for(int k = 0; k< word[i].size(); k++){
            char cOne = word[i].at(k);

            if(cOne == cTwo){
                location[0] = k; // value of common letter in first word
                location[1] = j; // value of common letter in second word
                common = true;
                return common;
                break;

                    }else{
                        /*while(j < word[i + 1].size()) {
                            char cTwo = word[i + 1].at(j);
                            if(cOne == cTwo) {
                                location[0] = k; // value of common letter in first word
                                location[1] = j; // value of common letter in second word
                                return true;
                            }
                            j++; // counter
                    } // end while j
                         */

                }// end if else
            } // end for k
        } // end while word size in bounds
        return common; // no match found
    } // end compare method


    void arrange(){
// j is columns, i is row
    bool horiz = false ; // for arranging word horizontal or not
         for(int i = 0; i < 4; i++){
             string temp = word[i];
             for (int j = 0; j< temp.size(); j++){ // want to put each letter into a spot in matrix
                     matrix[i][j] = temp.at(j) - 0; // add ascii value into matrix
                 //cout<< matrix[i][j] <<"";
             }
             //cout<<endl;
         }
        //horiz = !horiz; // swap horizontal
     }// end arrange


    void randFill(){
        srand(unsigned (1)); // random generator, seed of 1
        //cout<< random;
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(matrix[i][j] == 32){
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
