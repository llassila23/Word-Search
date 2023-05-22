// Programmer: Lucas Lassila
// 05.14.2023
// CS 145
// assignment 1 Word Search
// This program is meant to take words from a user and put them in a word search

#include "Manager.h"

using namespace std;
int main(){

    WordSearch newWS;
    // instructions
    newWS.printWelcome();
    // set empty word search
    newWS.matrixToZero();
    // make word search for 6 words
    newWS.getWords();
    newWS.crossArrange(); // arranges first 2 words in a cross
    newWS.arrangeHorizontal(2); // arranges 3rd word horizontally
    newWS.arrangeVertical(3); // arranges 4th word vertically
    newWS.arrangeHorizontal(4);
    newWS.arrangeVertical(5);

    newWS.copyWS(); // save solution

    int choice =0; // for menu
    do{
    cout<< "Enter 1 to see The Word Search"<< endl;
    cout<< "2 to see the solutions"<< endl;
    cout<< "else, exit"<< endl;
    cin>>choice;

    switch(choice){ // display/exit menu
        case 1:
            newWS.randFill();
            newWS.wordSearchOut();
            break;
        case 2:
            newWS.copyOut(); // print solutions
            break;
        default:
            cout<< "goodbye";
            break;
    }// end switch
        }while(choice == 1 || choice == 2 );

return 0;
}// end main

/*Note:
 * This program is not very robust thus, I would like to include an acknowledgement of things I would do
 *  differently in the future.
 * 1. It is difficult to accept all the words at once. Arranging them with overlap would be easier to
 *  accomplish should all the words be handled individually as the user enters them
 *  and then seeing if any match.
 * 2. There is a lot of repetition in the printing and traversing of the arrays.
 *  It would be better to pass the different arrays into a single, more flexible method.
 * 3. Number 2 would also allow for a more universal coordinate system. This would allow easier
 *  locating of spaces and transferring the location of that space to the arrangement methods.
 * 4. File IO could be useful for storing the word searches once they have been made, freeing up
 *  resources.
 *  This would also allow for a library of past word searches which would be a neat feature.
 * */