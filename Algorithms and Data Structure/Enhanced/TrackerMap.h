/*
The purpose of the TrackerMap.h file is to declare the TrackMap class
and its member functions and private data member.
*/

#include <map>
#include <string>
using namespace std;

class TrackerHash {
public:
  TrackerHash(); // Constructor to initialize tracker hash table
  void loadFile(
  const string &filename); // Used to load data from a file into tracker map
  void displayMenu();          // Used to display menu options
  void searchItem(const string &item); // Search and output the item frequencies
  void printFrequencyList();           // Prints the item frequency list
  void printFrequencyHistogram(); // Print histogram of the item frequencies
  void saveFile(const string &filename); // Saves item frequencies into a file

private:
    struct Node {
        string item;
        int frequency;
        Node* next;
    };

    vector<Node*> hashTable; // Vector of linked lists
    int tableSize; // Size of the hash table
    int hashFunction(const string &item); // Function to compute hash value
};
