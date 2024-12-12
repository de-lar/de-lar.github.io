/*
The purpose of the TrackerMap.cpp file is to define the member functions of the TrackerMapClass.
It is designed to load data from a file, tracks the frenquency of the grocery items, display lists,
allows user to input an option from a displayed menu, and saves date into a file.
*/

#include "TrackerMap.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

TrackerMap::TrackerMap() { } //Constructor to initialize TrackerMap object

//Function to open a file and read the map
void TrackerMap::loadFile(const string& filename) {
    ifstream inputFile(filename); //Load data from file into trackermap
    
    string item;
    //Reads item data from file
    while (inputFile >> item) {
        trackerMap[item]++; //Increment count of the item in the map
    }
  
    inputFile.close(); //Close input file
}

//Function to display menu. Prompt uuser to select an option.
void TrackerMap::displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Print item frequency list" << endl;
    cout << "3. Print item frequency histogram" << endl;
    cout << "4. Exit" << endl;
}

//Function to search for an item in the map
void TrackerMap::searchItem(const string& item) {
    cout << trackerMap[item] << endl;
}

//Function to search and print the item frequency list
void TrackerMap::printFrequencyList() {
    cout << "Item Frequency List:" << endl;
    //Iterates through the map and prints frequencies
    for (const auto& pair : trackerMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

//Function to output histogram of item using asterisks
void TrackerMap::printFrequencyHistogram() {
    cout << "Item Frequency Histogram:" << endl;
  //Iterates through the map and prints frequency histograms
    for (const auto& pair : trackerMap) {
        cout << pair.first << " ";
        //Loop to print atericks according to item amount
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

//Function to save the item frequencies to a file
void TrackerMap::saveFile(const string& filename) {
    ofstream outputFile(filename); //Opens file for file writing
  
    //Iterates through the map and writes item frequencies into the output file
    for (const auto& pair : trackerMap) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close(); //Closes output file.
}