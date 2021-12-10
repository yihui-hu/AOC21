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
    
    // INCOMPLETE; ONLY PART 1 DONE. WILL UPDATE WITH PART 2 IF POSSIBLE.
  
    // contingent on knowing size of row and col. use vectors instead lol
    int nums[100][100];
    
    // input values into a 2d array
    char c;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            input_file >> c;
            int num = c - '0';
            nums[i][j] = num;
        }
    }
    
    // checking arrangement of cells
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << nums[i][j];
        }
        cout << endl;
    }
    
    int sum = 0;
    
    // possible permuations of moves to find adjacent cells
    static int moves[4][2] = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            bool valid = true;
            int curr = nums[i][j];
          
            // checks adjacent cells (horizontal & vertical only, not diagonally)
            for (int l = 0; l < 4; l++) {
                int ti = i + moves[l][0];
                int tj = j + moves[l][1];
                if ((ti < 0 or ti >= 100) or (tj < 0 or tj >= 100)) {
                    continue;
                }
                if (curr >= nums[ti][tj]) {
                    valid = false;
                }    
            }
            // if value is less than all adjacent cells, add it + 1 to sum
            if (valid) {
                cout << curr << endl;
                sum += (curr+1);
            }
        }
    }
    
    cout << sum << endl;

    return 0;
}
