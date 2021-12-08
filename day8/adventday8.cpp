#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>

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
  
    // part 1 solved around midnight, part 2 the next morning before cs recitation
    // warning; very ugly code...
    
    vector<string> ten;
    vector<string> four;

    int counter = 0;
    int sum = 0;
    
    while (not input_file.eof()) {
        string t;
        for (int i = 0; i < 10; i++) {
            input_file >> t;
            ten.push_back(t); // all ten values inputted here
        }
        
        // for storing all characters into a key of some sort
        string one, two, three, four, five, six, seven, eight, nine, zero;
        
        for (string m : ten) {
            if (m.length() == 2) {
                one = m;
            } else if (m.length() == 3) {
                seven = m;
            } else if (m.length() == 4) {
                four = m;
            } else if (m.length() == 7) {
                eight = m;
            }
        }
        
        // some logic involved: 9 involves all characters of 1 and 4, 0 involves all characters of 1, and 6 is just.. 6 (lol) by elimination
        for (string m : ten) {
            if (m.length() == 6) {
                if (m.find(one[0]) != std::string::npos and m.find(one[1]) != std::string::npos) {
                    if (m.find(four[0]) != std::string::npos and m.find(four[1]) != std::string::npos and m.find(four[2]) != std::string::npos and m.find(four[3]) != std::string::npos) {
                        nine = m;
                    } else {
                        zero = m;
                    }
                } else {
                    six = m;
                }
            }
        }
        
      // same logic... 3 involves only characters of 1, 5 involves all but one characters of 6, 2 is 2 by elimination
        for (string m : ten) {
            if (m.length() == 5) {
                if (m.find(one[0]) != std::string::npos and m.find(one[1]) != std::string::npos) {
                    three = m;
                } else {
                    if (six.find(m[0]) != std::string::npos and six.find(m[1]) != std::string::npos and six.find(m[2]) != std::string::npos and six.find(m[3]) != std::string::npos and six.find(m[4]) != std::string::npos) {
                        five = m;
                    } else {
                        two = m;
                    }
                }
            }
        }
        
        char c;
        input_file >> c; // for the delimiter
        
        string f;
        vector<int> four_num(0);
        
        // checking the four numbers after the delimiter
        for (int i = 0; i < 4; i++) {
            input_file >> f;
            
            if (f.length() == 2) {
                four_num.insert(four_num.begin(), 1);
            } else if (f.length() == 3) {
                four_num.insert(four_num.begin(), 7);
            } else if (f.length() == 4) {
                four_num.insert(four_num.begin(), 4);
            } else if (f.length() == 7) {
                four_num.insert(four_num.begin(), 8);
            
            // BEGINNING OF EXTREMELY SCUFFED CONDITIONALS :^) 
            } else if (f.length() == 6) {
                // check if characters match those of 9, 0, 6
                if (f.find(nine[0]) != std::string::npos and f.find(nine[1]) != std::string::npos and f.find(nine[2]) != std::string::npos and f.find(nine[3]) != std::string::npos and f.find(nine[4]) != std::string::npos and f.find(nine[5]) != std::string::npos) {
                    four_num.insert(four_num.begin(), 9);
                } else if (f.find(zero[0]) != std::string::npos and f.find(zero[1]) != std::string::npos and f.find(zero[2]) != std::string::npos and f.find(zero[3]) != std::string::npos and f.find(zero[4]) != std::string::npos and f.find(zero[5]) != std::string::npos) {
                    four_num.insert(four_num.begin(), 0);
                } else if (f.find(six[0]) != std::string::npos and f.find(six[1]) != std::string::npos and f.find(six[2]) != std::string::npos and f.find(six[3]) != std::string::npos and f.find(six[4]) != std::string::npos and f.find(six[5]) != std::string::npos) {
                    four_num.insert(four_num.begin(), 6);
                }
                
            } else if (f.length() == 5) {
                // check if characters match those of 3, 5, 2
                if (f.find(three[0]) != std::string::npos and f.find(three[1]) != std::string::npos and f.find(three[2]) != std::string::npos and f.find(three[3]) != std::string::npos and f.find(three[4]) != std::string::npos) {
                    four_num.insert(four_num.begin(), 3);
                } else if (f.find(five[0]) != std::string::npos and f.find(five[1]) != std::string::npos and f.find(five[2]) != std::string::npos and f.find(five[3]) != std::string::npos and f.find(five[4]) != std::string::npos) {
                    four_num.insert(four_num.begin(), 5);
                } else if (f.find(two[0]) != std::string::npos and f.find(two[1]) != std::string::npos and f.find(two[2]) != std::string::npos and f.find(two[3]) != std::string::npos and f.find(two[4]) != std::string::npos) {
                    four_num.insert(four_num.begin(), 2);
                }
            }
        }
        
        int number = 0;
        
        // the four digit number
        number += four_num[3] * 1000;
        number += four_num[2] * 100;
        number += four_num[1] * 10;
        number += four_num[0];
        
        sum += number; // add four digit number to running sum
        
        // end of one display, clear everything and move onto next
        ten.clear();
        four.clear();
        four_num.clear();
    }
    
    cout << sum << endl;

    return 0;
}
