/*
The purpose of the TrackerMap.h file is to declare the TrackMap class
and its member functions and private data member.
*/

#include <map>
#include <string>
using namespace std;

class TrackerMap {
public:
  TrackerMap(); // Constructor to initialize tracker map
  void loadFile(
      const string &filename); // Used to load data from a file into tracker map
  void displayMenu();          // Used to display menu options
  void searchItem(const string &item); // Search and output the item frequencies
  void printFrequencyList();           // Prints the item frequency list
  void printFrequencyHistogram(); // Print histogram of the item frequencies
  void saveFile(const string &filename); // Saves item frequencies into a file

private:
  map<string, int>
      trackerMap; // Private member variable to store frequencies of items
};
