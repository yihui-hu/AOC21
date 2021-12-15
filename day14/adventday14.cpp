#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

int main(int argc, char *argv[]) 
{
    string filename = argv[1];
    
    ifstream input_file;
    
    input_file.open(filename);
    
    if (not input_file.is_open()) {
        cerr << "fileread.cpp: could not open file: "
             << filename << endl;
        return 1; 
    }
  
    // only part 1; still using good ol' vectors...
    
    string temp;
    vector<char> left;
    vector<char> right;
    vector<char> insert;
    vector<char> polymer;
    
    input_file >> temp;
    
    for (int i = 0; i < temp.length(); i++) {
        polymer.push_back(temp[i]);
    }
    
    cout << "Before: ";
    for (char m : polymer) {
        cout << m;
    }
    cout << endl;
    
    while (not input_file.eof()) {
        string temp;
        char tleft;
        char tright;
        char tinsert;
        input_file >> tleft;
        input_file >> tright;
        input_file >> temp;
        input_file >> tinsert;
        left.push_back(tleft);
        right.push_back(tright);
        insert.push_back(tinsert);
    }
    
    // for some reason it reads in the last line twice, so i have to manually delete them from the vectors. will have to look into this
    left.pop_back();
    right.pop_back();
    insert.pop_back();
    
    
    // debugging
//     for (char m : left) {
//         cout << m;
//     }
//     cout << endl;
    
//     for (char m : right) {
//         cout << m;
//     }
//     cout << endl;
    
//     for (char m : insert) {
//         cout << m;
//     }
//     cout << endl;
    
    vector<int> indices;
    vector<char> to_insert;
    
    // no. of steps to take. 10 for pt 1, 40 for pt 2 rip
    for (int i = 0; i < 40; i++) {
        
        // cout << "CURRENT: " << endl;
        // for (char m : polymer) {
        //     cout << m;
        // }
        // cout << endl;
        
        for (int i = 0; i < polymer.size() - 1; i++) {
            char left_t = polymer[i];
            char right_t = polymer[i+1];
            for (int j = 0; j < left.size(); j++) {
                if (left_t == left[j] and right_t == right[j]) {
                    // cout << j << ":" << left[j] << right[j] << endl;
                    // cout << left_t << ", " << right_t << endl;
                    indices.push_back(i+1);
                    to_insert.push_back(insert[j]);
                }
            }
        }
        
        // to account for vector increasing at every insertion
        int counter = 0;
        
        // for (char m : to_insert) {
        //     cout << m << ",";
        // }
        // cout << endl;
        
        for (int i = 0; i < indices.size(); i++) {
            int index = indices[i] + counter;
            // cout << index << ",";
            char inserting = to_insert[i];
            polymer.insert(polymer.begin() + index, inserting);
            counter++;
        }
        
        // clear vector for the next step
        indices.clear();
        to_insert.clear();
        
        // print out current polymer at every step, for debugging
        cout << "After: ";
        for (char m : polymer) {
            cout << m;
        }
        cout << endl;
    }
    
    // using maps to find no. of times a character appears in the polymer
    map<long, long> counters;
    for(char m : polymer) {
        counters[m]++;
    }
    
    long maximum = 0;
    
    // finding max
    for (auto m : counters) {
        if (m.second > maximum) {
            maximum = m.second;
        }
    }
    
    cout << maximum << endl;
    
    // finding min
    for (auto m : counters) {
        if (m.second < maximum) {
            maximum = m.second;
        }
    }
    
    cout << maximum << endl;
    
    return 0;
}
