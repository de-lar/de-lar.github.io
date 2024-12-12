/*
Alexandra Delarosa
Project 3: Grocery tracking app

The purpose of the grocery tracker app is to allow Corner Grocer to analyze and track their grocery item data.
It provides a user interface and diplays a menu with options from 1 through 4

Option 1 allows a user to see how many times an item is on a list.
Option 2 allows a user to see a list of all items in the file along with the frequency number.
Option 3 allows a user to see a list of all items in the file along with an asterick histogram number.
Option 4 allows a user to exit the program.
*/

#include <iostream>
#include "TrackerMap.h"
using namespace std;

int main() {
    TrackerMap cornerGrocer; //Creates an instance of TrackerMap class
    cornerGrocer.loadFile("CS210_Project_Three_Input_File.txt"); //Load data from input file

    int option; //Used to store user input
  
    //Program loops until user enter "4"
    while (option != 4){
        //Displays menu, prompts user to input an option, then stores input
        cornerGrocer.displayMenu();
        cout << "Enter an option: ";
        cin >> option;

        //Handles what to do based on what option user choose
        switch (option) {
            //If user chose 1, search for item in the file
            case 1: {
                string searchItem; 
                cout << "Enter the item name: ";
                cin >> searchItem;
                cornerGrocer.searchItem(searchItem);
                break;
            }
            //If user chose 2, print frequency list
            case 2: {
                cornerGrocer.printFrequencyList();
                break;
            }
            //If user chose 3, print frequency histogram
            case 3: {
                cornerGrocer.printFrequencyHistogram();
                break;
            }
            //If user chose 4, end the program
            case 4:
                cout << "Program finished" << endl;
                break; //Ends the program
            //If user enters an number not from 1 - 4, display error message
            default:
                cout << "Not a valid choice" << endl;
        }
    } 

    //Save item frequencies into an output file
    cornerGrocer.saveFile("frequency.dat");

    return 0;
}