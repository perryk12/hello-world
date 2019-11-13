// Katherine Perry Project 2

#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <algorithm>
using std::sort;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <string>
using std::string; 
#include <iterator>

// function that returns the integer character difference of 2 strings
int calculate_difference(string a, string b) {
    int min_length = static_cast<int>(std::min(a.length(), b.length()));
    int difference = 0;
    for(int i = 0; i < min_length; ++i) {
        if(a[i] != b[i]) {
            difference++;
        }
    }
    // count length difference in character difference
    if(a.length() != b.length()) {
        difference += static_cast<int>(abs(a.length() - b.length()));
    }
    return difference;
}

int main() {
    // read in from file and push back into a vector
    ifstream input("common_passwords.txt");
    string password;
    int difference;
    vector<string> common_passwords;
    while(input >> password) {
        common_passwords.push_back(password);
    }
    // interact with user to get password
    cout << "Give me a password: ";
    cin >> password;
    cout << "You provided a password of " << password << endl;
    // create a map of password vectors and their corresponding character differences
    cout << "The most similar passwords to " << password << " are:" << endl;
    map<int,vector<string>> linked_words;
    for(string p : common_passwords) {
        difference = calculate_difference(password, p);
        linked_words[difference].push_back(p);
    }
    // print the most similar passwords based on incrementing the difference key
    // sort the corresponding string vector alphabetically first
    for(int i = 0, count = 0; i < 15 && count < 1; i++) {
        if(linked_words.count(i) == 1) {
            sort(linked_words[i].begin(), linked_words[i].end());
            for(auto itr = linked_words[i].begin(); itr != linked_words[i].end(); ++itr) {
                cout << *itr << ", ";
            }
            count++;
            cout << "\nAll of which are " << i << " character(s) different." << endl;
        }
    }
    
}



