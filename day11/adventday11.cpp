#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

// recursive function. should've named it better like flash or something lol
void recurse(int i, int j, int s[][10]);

// somehow managed to scrape by and implement recursion for this puzzle. cool! i can head to bed slightly earlier tonight.

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
    
    int s[10][10]; // 2D array of given dimensions 10 x 10
    int total = 0; // track total no. of flashes
    
    // input... could use getline if dimensions are not known i guess
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            input_file >> c;
            int num = c - '0';
            s[i][j] = num;    
        }
    }
    
    // check initial state of matrix, for debugging 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << s[i][j]; 
        }
        cout << endl;
    }
    
    // for part 1 it is specified, for part 2, i'm not sure... i guess use a while (not all flashing) loop
    int steps = 500;
    
    // iterate according to no. of steps
    for (int m = 0; m < steps; m++) {
        // add 1 to each octopus 
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                s[i][j]++;
            }
      
        // check for any octopus that are >9 using recursive function
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                recurse(i, j, s);
            }
        }
        
        // part 1 => at each iteration check for octopus that flashed (i.e. now 0), add to running total
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i][j] == 0) {
                    total++;
                }
            }
        }
        
        // part 2 => check if matrix displays all 0; if so, break out of loop and return current step of the loop + 1 (i.e. m+1)
        bool valid = true;
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i][j] != 0) {
                    valid = false;
                }
            }
        }
        
        if (valid) {
            cout << m+1 << endl;
            break;
        }
        
    }
    
    // debugging for part 1 and 2 --> checks state of board after a certain no. of steps
    cout << "AFTER: " << endl;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << s[i][j]; 
        }
        cout << endl;
    }  
    
    // part 1 => return total number of times octopus flashed
    cout << total << endl;
    
    return 0;
}

void recurse(int i, int j, int s[][10]) {
    
    // array of possible moves to reach adjacent elements in array, including diagonals
    static int moves[8][2] = {{-1,0}, {0, -1}, {1, 0}, {0, 1}, {1,1}, {-1,-1}, {1, -1}, {-1, 1}};
    
    int row = i;
    int col = j;
    
    // if the current octopus has value > 9
    if (s[row][col] > 9) {
        // set that octopus to 0
        s[row][col] = 0;
        // check adjacent tiles now and add 1 to them
        for (int l = 0; l < 8; l++) {
            int ti = row + moves[l][0];
            int tj = col + moves[l][1];
            // if out of range, ignore
            if ((ti < 0 or ti >= 10) or (tj < 0 or tj >= 10)) {
                continue;
            } else {
                // if octopus has not previously flashed, add 1
                if (s[ti][tj] != 0) {
                    s[ti][tj]++;
                }
            }
            // once done, check if that octopus >9 -- if so, call recursive function again
            if (s[ti][tj] > 9) {
                recurse(ti, tj, s);
            }
        }
    }
}
