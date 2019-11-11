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
int calculate_diff(string a, string b) {
    int min_l = static_cast<int>(std::min(a.length(), b.length()));
    int diff = 0;
    for(int i = 0; i < min_l; ++i) {
        if(a[i] != b[i]) {
            diff++;
        }
    }
    // count length difference in character difference
    if(a.length() != b.length()) {
        diff += static_cast<int>(abs(a.length() - b.length()));
    }
    return diff;
}

int main() {
    // read in from file and push back into a vector
    ifstream input("common_passwords.txt");
    string password;
    int difference;
    vector<string> common;
    while(input >> password) {
        common.push_back(password);
    }
    // interact with user to get password
    cout << "Give me a password: ";
    cin >> password;
    cout << "You provided a password of " << password << endl;
    // create a map of password vectors and their corresponding character differences
    cout << "The most similar passwords to " << password << " are:" << endl;
    map<int,vector<string>> links;
    for(string p : common) {
        difference = calculate_diff(password,p);
        links[difference].push_back(p);
    }
    // print the most similar passwords based on incrementing the difference key
    // sort the corresponding string vector alphabetically first
    for(int i = 0, count = 0; i < 15 && count < 1; i++) {
        if(links.count(i) == 1) {
            sort(links[i].begin(), links[i].end());
            for(auto itr = links[i].begin(); itr != links[i].end(); ++itr) {
                cout << *itr << ", ";
            }
            count++;
            cout << "\nAll of which are " << i << " character(s) different." << endl;
        }
    }
    
}



