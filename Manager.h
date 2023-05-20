// The Manager file for the Assignment 1: Word Search
// Created by Lucas Lassila on 5/15/23.
//

#ifndef ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
#define ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
// methods defined here
#include <iostream> // input and output
#include <random> // random number generation
#include<cstdlib>
#include <fstream> // file io
#include <string>

using namespace std;

class Manager {
public:
    // constructor, value initialization of array word[]

        string word[6] = {};// array that can hold six words
        int matrix [12][12] = {};
        int copy [12][12] ={}; // to be used to store solutions before matrix is filled
        int location[2] = {0,0};

};

class WordSearch : public Manager{ // inherit the arrays from manager
    public:
    int loc = 0; // int to help store location of common values
    int m=12, n=12 ;// dimensions for matrix
    int wordSize = 4;
    int spacer; // for horizontal offset

    void printWelcome(){
        string line;
        //string fileName = "WELCOME.txt";
        //fstream file;
        //ifstream file;
        std:: ifstream file("WELCOME.txt");


        if(file.is_open()){
        while(getline (file,line))
        {
            cout<< line<< endl;
        }
        file.close();
        }
        else  cout<< "unable to open file" << endl;

    }
    void matrixToZero(){ // fill array with empty spaces
        for(int i = 0; i<m; i++){
            for (int j = 0; j <= n; j++) {
                matrix[i][j] = 32; // ascii value of a empty space
            }
        }

    }


     void getWords(){ // method to put users word choice into word[]
        cout<< "please enter a 2-12 letter word when prompted"<< endl;
        for(int i = 0; i<= 5; i++){
            cout<< "enter a word"<< endl;
            cin >> word[i];
        }
        return;
    }// end get words

    // precondition: empty matrix, first two words can be overlapped.
    // postconditoin: matrix has 2 words arranged in it.
    void crossArrange() { // calls compare, meant to arrange words, references location[]

        bool common = false; // does the next word have a common letter?

        for (int i = 0; i < wordSize; i++) { // to get word

                string wordOne = word[i];
                 spacer = m - wordOne.size(); // spacer to offset from position zero
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
            }// end if common is found
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

                }// end if else
            } // end for k
        } // end while word size in bounds
        return common; // no match found
    } // end compare method

// precondition: word[0] & word[1] have been arranged, i = next word to be arranged
    void arrangeHorizontal(int i){// method for horizontal arranging
        string temp = word[i]; // word to be arranged
        bool space = false ; //is there enough space for temp?
        int column = 0; // column will be refernced again in filling
        int row = 0;
        spacer++;
        // to search for empty row
        for( row =0 ; row < m; row++){
                while(matrix[row][column] == 32 && column+2 <= n ){
                        if(matrix[row][column + 1] !=32 || matrix[row][column+2] !=32){ // if both not zero, chances are row is full
                            space = space; // still false
                            break; // exit loops
                        } else{
                            column++; // advance
                            if(column == temp.size()) {
                                space = true;
                                break;
                            }// end if

                            // do loop again
                        } // end if else

                }// end while
            if(space){
                break; // catch, space found, no need to seach longer
            }

        }// end row, row var will be set if space is true


        // print the word
        while(space){
            column -= temp.size(); // reset back to start of empty row space to add in the word
            for (int k = 0; k< temp.size(); k++){
                matrix[row+spacer][column+spacer+k] = temp.at(k) - 0; // print that word in that column // 3 is offset
            }
        space = !space;  // exit while loop
        } // end while space

     }// end arrangeHorizontal

// same as arrangeHorizontal, except row logic has been applied to columns
    void arrangeVertical(int i){// method for horizontal arranging the 4th word
        string temp = word[i]; // word to be arranged
        bool space = false ; //is there enough space for temp?
        int column = m ; // column will be refernced again in filling
        int row = 0;
            int offset = 2*i -1;

        // to search for empty row
        for( column = m; column > 0; column--){ // go backwards
            while(matrix[row][column] == 32 && row+2 <= n ){
                if(matrix[row +1][column] !=32 || matrix[row+2][column] !=32){ // if both not zero, chances are row is full
                    space = space; // still false
                    break; // exit loops
                } else{
                    row++; // advance
                    if(row == temp.size()) {
                        space = true;
                        break;
                    }// end if

                    // do loop again
                } // end if else

            }// end while
            if(space){
                break; // catch, space found, no need to seach longer
            }

        }// end row, row var will be set if space is true


        // print the word
        while(space){
            row -= temp.size(); // reset back to start of empty row space to add in the word
            for (int k = 0; k< temp.size(); k++){
                matrix[row+k][column + offset] = temp.at(k) - 0; // print that word in that column
            }
            space = !space;  // exit while loop
        } // end while space

    }// end arrange

    void copyWS(){
        for (int i = 0; i < m; i++){
            for (int j =0; j<n ; j++) {
                copy[i][j] = matrix[i][j]; // set them equal
            }
        }
    }// end copyWS


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
    }// end WS out

    void copyOut(){ // print solutions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = copy[i][j];
                cout << ch ;
            }
            cout <<endl;
        }
    }// end copy out



};
#endif //ASSIGNMENT_1_WORD_SEARCH_MANAGER_H
