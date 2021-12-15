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
    
    // alternate solution to part 1 using maps. thought it would help for part 2. a fruitless endeavour, but maps are super fun.
  
    string temp;
    vector<char> left;
    vector<char> right;
    vector<char> insert;
    map<string, int> polymer;
    
    input_file >> temp;
    
    for (int i = 0; i < temp.length() - 1; i++) {
        string l;
        l += temp[i];
        l += temp[i+1];
        polymer[l]++;
    }
    
    cout << "Before: ";
    for (auto m : polymer) {
        cout << m.first << ",";
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
    
    left.pop_back();
    right.pop_back();
    insert.pop_back();
    
    for (char m : left) {
        cout << m;
    }
    cout << endl;
    
    for (char m : right) {
        cout << m;
    }
    cout << endl;
    
    for (char m : insert) {
        cout << m;
    }
    cout << endl;
    
    vector<int> indices;
    vector<char> to_insert;
    map<string, int> new_polymer;
    
    for (auto m : polymer) {
        new_polymer[m.first]++;
    }
    
    for (int i = 0; i < 40; i++) {
        for (auto m : polymer) {
            for (int j = 0; j < left.size(); j++) {
                string test;
                test += left[j];
                test += right[j];
                if (m.first == test and m.second > 0) {
                    for (int k = 0; k < m.second; k++) {
                        // cout << "splitting: " << m.first << endl;
                        // cout << "quantity: " << m.second << endl;
                        string new1;
                        new1 += (m.first)[0];
                        new1 += insert[j];
                        // cout << new1 << endl;
                        string new2;
                        new2 += insert[j];
                        new2 += (m.first)[1];
                        // cout << new2 << endl;
                        new_polymer[new1]++;
                        new_polymer[new2]++;
                        new_polymer[m.first]--;
                    }
                }
            }
        }
        
        polymer.clear();
        
        for (auto m : new_polymer) {
            if (m.second > 0) {
                polymer[m.first] += m.second;
            }
        }
        cout << "Done" << endl;
    }
    
    cout << "After: " << endl;
    for (auto m : new_polymer) {
        cout << m.first << ",";
    }
    cout << endl;
    for (auto m : new_polymer) {
        cout << m.second << ",";
    }
    cout << endl;
    
    map<char, int> final;
    
    for (auto m : new_polymer) {
        final[m.first[0]] += m.second;
    }
    
    for (auto m : final) {
        cout << m.first << ",";
        cout << m.second << ", ";
    }
    cout << endl;
    
    long maximum = 0;
    char max;
    
    for (auto m : final) {
        if (m.second > maximum) {
            maximum = m.second;
            max = m.first;
        }
    }
    
    cout << max << ":" << maximum << endl;
    
    // map<long, long> counters;
    // for(char i : polymer) {
    //     ++counters[i];
    // }
    // 
    // long maximum = 0;
    // 
    // for (auto m : counters) {
    //     if (m.second > maximum) {
    //         maximum = m.second;
    //     }
    // }
    // 
    // cout << maximum << endl;
    // 
    // for (auto m : counters) {
    //     if (m.second < maximum) {
    //         maximum = m.second;
    //     }
    // }
    // 
    // cout << maximum << endl;
    
    return 0;
}
