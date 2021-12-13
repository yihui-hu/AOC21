#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

void fold_y(int fold, int new_row, int new_col, vector<vector<char>>& vect);
void fold_x(int fold, int new_row, int new_col, vector<vector<char>>& vect);

// today wasn't so bad, at least i didn't have to learn new tech for this...

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
    
    vector<int> row, col;
    
    // your good ol' manual stop of 847... yup
    for (int i = 0; i < 847; i++) {
        int x;
        int y;
        char c;
        input_file >> x;
        input_file >> c;
        input_file >> y;
        col.push_back(x);
        row.push_back(y);
    }
    
    // determine no. of rows and cols required for the paper
    int cols = *max_element(col.begin(), col.end()) + 1;
    int rows = *max_element(row.begin(), row.end()) + 1;
    cout << "ROWS: " << rows << " - "  << "COLS: " << cols << endl; // debugging stuff
    
    vector<char> line;
    vector<vector<char>> paper;
    char empty = '.'; // initialise each point on the paper with '.'
    
    for (int i = 0; i < cols; i++) {
        line.push_back(empty);
    }
    
    for (int i = 0; i < rows; i++) {
        paper.push_back(line);
    }
    
    // for each matching pair of x and y values in row and col, find that coord on the paper and mark it with '#'
    for (int i = 0; i < 847; i++) {
        paper[row[i]][col[i]] = '#';
    }
    
    // for debugging purposes
    // for (int i = 0; i < rows; i++) {
    //     for (char m : paper[i]) {
    //         cout << m;
    //     }
    //     cout << endl;
    // }
    
    // update constraints for every fold so that end result displays only folded portion
    int new_row = rows;
    int new_col = cols;
    
    // what the fuck lmao sorry i wish i knew a better way but this will have to do for now. will revisit it after finals i guess
    fold_x(655, new_row, new_col, paper);
    new_col = 655;
    fold_y(447, new_row, new_col, paper);
    new_row = 447;
    fold_x(327, new_row, new_col, paper);
    new_col = 327;
    fold_y(223, new_row, new_col, paper);
    new_row = 223;
    fold_x(163, new_row, new_col, paper);
    new_col = 163;
    fold_y(111, new_row, new_col, paper);
    new_row = 111;
    fold_x(81, new_row, new_col, paper);
    new_col = 81;
    fold_y(55, new_row, new_col, paper);
    new_row = 55;
    fold_x(40, new_row, new_col, paper);
    new_col = 40;
    fold_y(27, new_row, new_col, paper);
    new_row = 27;
    fold_y(13, new_row, new_col, paper);
    new_row = 13;
    fold_y(6, new_row, new_col, paper);
    new_row = 6;
    
    cout << "NEW ROW: " << new_row << " - " << "NEW COL: " << new_col << endl; // debugging

    // part 1 stuff;
    //
    // fold_x(655, new_row, new_col, paper);
    // new_col = 655;
    //
    // int sum = 0;
    // 
    // for (int i = 0; i < new_row; i++) {
    //     for (int j = 0; j < new_col; j++) {
    //         if (paper[i][j] == '#') {
    //             sum++;
    //         }
    //     }
    // }
    // 
    // cout << sum << endl;
    
    for (int i = 0; i < new_row; i++) {
        for (int j = 0; j < new_col; j++) {
            cout << paper[i][j];
        }
        cout << endl;
    }
    
    return 0;
}

// the hard part was figuring out the math to get the paper to fold correctly lol 

void fold_x(int fold, int new_row, int new_col, vector<vector<char>> &vect) {
    int symmetry_x = 1;
    
    for (int i = 0; i < new_row; i++) {
        for (int j = fold + 1; j < new_col; j++) { // basically only search every row below the fold on the x-axis
            if (vect[i][j] == '#') {
                vect[i][fold-symmetry_x] = '#'; // then map it to the top accordingly with maf
            }
            symmetry_x++;
        }
    }
}

void fold_y(int fold, int new_row, int new_col, vector<vector<char>> &vect) {
    int symmetry_y = 1;

    for (int i = fold + 1; i < new_row; i++) { // search only every column after the fold on the y-axis
        for (int j = 0; j < new_col; j++) {
            if (vect[i][j] == '#') {
                vect[fold-symmetry_y][j] = '#'; // map it to the left accordingly
            }
        }
        symmetry_y++;
    }
}
