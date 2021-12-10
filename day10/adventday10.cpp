#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

int main()
{
    ifstream f("advent10.txt");
    
    string in;
    vector<string> lines;
    
    while (getline(f, in)) {
        lines.push_back(in);
    }
    
    // had to teach myself deque for this shit... 2am vibes
    deque<char> open;
    
    // crude key, would definitely use ro, co, so, ao instead of wasting time with underscores.. dummy
    // i imagine you could use maps somehow, but i don't know much about it yet and i am quite tired
    char r_o = '(';
    char c_o = '{';
    char s_o = '[';
    char a_o = '<';
    char r_c = ')';
    char c_c = '}';
    char s_c = ']';
    char a_c = '>';
    
    vector<char> errors;
    vector<long> results;
    
    for (int i = 0; i < lines.size(); i++) {
        
        string line = lines[i];
        bool valid = true; // to check if closing bracket is valid, if not break out of loop immediately and return invalid closing bracket or do smth else
        long sum = 0; // useful for part 2 and 1
        
        // for checking through each character of the line
        for (int j = 0; j < line.length(); j++) {
            
            // if char is an opening bracket, add it to the deque
            if (line[j] == r_o or 
                line[j] == c_o or 
                line[j] == s_o or 
                line[j] == a_o) {
                open.push_front(line[j]);
            }
            
            char curr = open.front();
            cout << curr << endl; // debugging
            char next = line[j+1]; // check next character in the same iteration of loop
            
            // if it is a closing bracket, check if it corresponds with the opening bracket at front of deque
            if (next == r_c or 
                next == c_c or 
                next == s_c or 
                next == a_c) { 
                    
                if (curr == r_o and next != r_c) {
                    errors.push_back(next); // add to vector for part 1 purposes
                    valid = false; // if it does not match, return false so it breaks out of the loop later on. this line is donezo, move onto the next
                } else if (curr == c_o and next != c_c) {
                    errors.push_back(next);
                    valid = false;
                } else if (curr == s_o and next != s_c) {
                    errors.push_back(next);
                    valid = false;
                } else if (curr == a_o and next != a_c) {
                    errors.push_back(next);
                    valid = false;
                }
                open.pop_front(); // if it matches, remove it from the deque
            }
            if (not valid) {
                open.clear(); // clear open for the next line
                break; // immediately move onto next line
            }
        }
        
        // well, since we already have a deque of opening brackets, return the straddlers that don't have a match after running through the entire line
      
        cout << "RUN: " << i+1 << endl;
        while (!open.empty() and valid) { // must be a valid line that ends abruptly
            char yup = open.front();
            cout << yup << endl; // useful for debugging
            // add to a sum of sorts for each element in deque, then remove it and move on
            if (yup == r_o) {
                sum = sum * 5;
                sum += 1;
                open.pop_front();
            } else if (yup == c_o) {
                sum = sum * 5;
                sum += 3;
                open.pop_front();
            } else if (yup == s_o) {
                sum = sum * 5;
                sum += 2;
                open.pop_front();
            } else if (yup == a_o) {
                sum = sum * 5;
                sum += 4;
                open.pop_front();
            }
        }
        cout << "END" << endl;
        
        if (sum > 0) { // for lines that are complete or have an invalid closing bracket, sum will be 0, so check for anything more than 0
            results.push_back(sum);
        }
        sum = 0;
    }
    
    // sort array :^)
    sort(results.begin(), results.end());

    // spec says that there will always be an odd no. of scores to consider, so find median using simple formula:
    int median = (results.size()-1)/2;
    
    cout << results[median] << endl;
  
    // debugging stuff:
    //     for (long m : results) {
    //         cout << m << endl;
    //     }
    
    // part 1 stuff
    
    // for (char m : errors) {
    //     if (m == c_c) {
    //         sum += 1197;
    //     } else if (m == s_c) {
    //         sum += 57;
    //     } else if (m == a_c) {
    //         sum += 25137;
    //     } else if (m == r_c) {
    //         sum += 3;
    //     }
    // }
    // 
    // cout << sum << endl;
    
    return 0;
}

// char recursive() {
//  // i wanted to do some recursive shit but gave up the ghost 
// }
