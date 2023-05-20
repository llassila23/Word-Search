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
    cout<< "3 to exit"<< endl;
    cin>>choice;

    switch(choice){
        case 1:
            newWS.randFill();
            newWS.wordSearchOut();
            break;
        case 2:
            newWS.copyOut(); // print solutions
            break;
        case 3:
            cout<< "goodbye";
            break;
    }// end switch
        }while(choice == 1 || choice == 2 && choice != 3 );



return 0;
}

