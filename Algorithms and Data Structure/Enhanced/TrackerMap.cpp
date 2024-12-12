/*
The purpose of the TrackerMap.cpp file is to define the member functions of the TrackerMapClass.
It is designed to load data from a file, tracks the frenquency of the grocery items, display lists,
allows user to input an option from a displayed menu, and saves date into a file.
*/

#include "TrackerHash.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

TrackerMap::TrackerMap() { } //Constructor to initialize TrackerMap object

//Function to open a file and read the map
void TrackerHash::loadFile(const string &filename) {
    ifstream inputFile(filename);
    string item;
    while (inputFile >> item) {
        insertItem(item);
    }
    inputFile.close();
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
void TrackerHash::searchItem(const string &item) {
    int index = hashFunction(item);
    Node* current = hashTable[index];
    while (current) {
        if (current->item == item) {
            cout << current->item << ": " << current->frequency << endl;
            return;
        }
        current = current->next;
    }
    cout << "Item not found." << endl;
}

//Function to search and print the item frequency list
void TrackerHash::printFrequencyList() {
    cout << "Item Frequency List:" << endl;
    for (int i = 0; i < tableSize; i++) {
        Node* current = hashTable[i];
        while (current) {
            cout << current->item << " " << current->frequency << endl;
            current = current->next;
        }
    }
}

//Function to output histogram of item using asterisks
void TrackerHash::printFrequencyHistogram() {
    cout << "Item Frequency Histogram:" << endl;
    for (int i = 0; i < tableSize; i++) {
        Node* current = hashTable[i];
        while (current) {
            cout << current->item << " ";
            for (int j = 0; j < current->frequency; j++) {
                cout << "*";
            }
            cout << endl;
            current = current->next;
        }
  

void TrackerHash::saveFile(const string &filename) {
    ofstream outputFile(filename);
    for (int i = 0; i < tableSize; i++) {
        Node* current = hashTable[i];
        while (current) {
            outputFile << current->item << " " << current->frequency << endl;
            current = current->next;
        }
    }
    outputFile.close();
}