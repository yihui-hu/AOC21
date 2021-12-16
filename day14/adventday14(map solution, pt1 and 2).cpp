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
    
    // yes new approach using maps since part 2 was another lanternfish problem...
    // see line 116, that line is what caused me to have to debug this for hours over two days...
    
    if (not input_file.is_open()) {
        cerr << "fileread.cpp: could not open file: "
             << filename << endl;
        return 1; 
    }
    
    string temp; // read in polymer as a whole string. for debugging purposes
    
    vector<string> combos; // read in individual pairs
    vector<char> insert; // read in character to insert, index corresponds to individual pairs
    
    map<string, long> polymer; // split up polymer into individual pairs by index (0 with 1, 1 with 2, etc.) use maps to see how many pairs exist
    map<char, long> chars; // split up polymer into individual characters, track their quantity using maps
    
    // the following long list of code is for debugging and checking
    
//     input_file >> temp;
//     cout << endl;
//     cout << "Sequence: " << temp << endl;
    
//     cout << "Chars: ";
//     for (int i = 0; i < temp.length(); i++) {
//         chars[temp[i]]++;
//     }
    
//     for (auto m : chars) {
//         cout << m.first << ",";
//     }
//     cout << endl;
    
//     cout << "Quantity: ";
//     for (auto m : chars) {
//         cout << m.second << ", ";
//     }
//     cout << endl << endl;
    
//     cout << "Combos: ";
//     for (int i = 0; i < temp.length() - 1; i++) {
//         string l;
//         l += temp[i];
//         l += temp[i+1];
//         polymer[l]++;
//     }
//     for (auto m : polymer) {
//         cout << m.first << ",";
//     }
//     cout << endl;
    
//     cout << "Quantity: ";
//     for (auto m : polymer) {
//         cout << m.second << ", ";
//     }
//     cout << endl << endl;
    
    // finally reading in the file 
    while (not input_file.eof()) {
        string temp;
        string combo;
        char tinsert;
        input_file >> combo;
        input_file >> temp;
        input_file >> tinsert;
        combos.push_back(combo);
        insert.push_back(tinsert);
    }
    
    // lol
    combos.pop_back();
    insert.pop_back();
    
    // more debugging stuff after reading in the file
//     cout << "Combos:" << endl;
//     for (string m : combos) {
//         cout << m << ",";
//     }
//     cout << endl;
    
//     cout << "Insert:" << endl;
//     for (char m : insert) {
//         cout << m;
//     }
//     cout << endl << endl;
    
    // so that polymer doesn't expand as the loop runs through each step lol
    map<string, long> new_polymer;
    
    // make a copy of polymer in new_polymer
    for (auto m : polymer) {
        new_polymer[m.first] = m.second;
        // yup LMAO IT WAS new_polymer[m.first]++ AT FIRST...
        // IT THREW OFF THER REST OF THE PROGRAM... the test example only had one of each pair which is why it worked for that and not my input. sad
    }
    
    for (int i = 0; i < 40; i++) { // 40 for part 2, 10 for part 1
        for (auto m : polymer) { // for each pair in the polymer
            for (int j = 0; j < combos.size(); j++) { // check against list of approved pairs in combos vector
                if (m.first == combos[j]) { // if match is found,
                        string new1; 
                        new1 += (m.first)[0];
                        new1 += insert[j];
                        
                        string new2;
                        new2 += insert[j];
                        new2 += (m.first)[1];
                        
                        chars[insert[j]] += m.second; // add new character to list of characters according to no. of pairs in the polymer
                        new_polymer[new1] += m.second; // add newly created pair to polymer
                        new_polymer[new2] += m.second; // add the other newly created pair to polymer
                        new_polymer[m.first] -= m.second; // minus the original pair from polymer (since it is split by the middle char now)
                }
            }
        }
        
        polymer.clear(); // clear polymer for the next step in the loop
        
        for (auto m : new_polymer) {
            if (m.second > 0) { // copy over pairs from new_polymer into polymer excluding those with quantity 0
                polymer[m.first] = m.second;
            }
        }
    }
     
    // debugging stuff
//     for (auto m : chars) {
//         cout << m.first << ":";
//         cout << m.second;
//         cout << endl;
//     }
    
    cout << endl << "RESULTS:" << endl;
    
    long maximum = 0;
    char max;
    
    // normal counting stuff with maps
    for (auto m : chars) {
        if (m.second > maximum) {
            maximum = m.second;
            max = m.first;
        }
    }
    
    long maxx = maximum;
    
    cout << max << ":" << maximum << endl;
    
    for (auto m : chars) {
        if (m.second < maximum) {
            maximum = m.second;
            max = m.first;
        }
    }
    cout << max << ":" << maximum << endl;
    
    cout << endl << "Difference: " << maxx - maximum << endl << endl;
    
    // good riddance to day 14. time to move on
    
    return 0;
}
