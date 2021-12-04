#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include<bits/stdc++.h> 

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
    
    string throwaway;
    input_file >> throwaway;
    
    // taught myself a bit about vectors overnight for this!!!
    
    vector<int> num{ 85,84,30,15,46,71,64,45,13,90,63,89,62,25,87,68,73,47,65,78,2,27,67,95,88,99,96,17,42,31,91,98,57,28,38,93,43,0,55,49,22,24,82,54,59,52,3,26,9,32,4,48,39,50,80,21,5,1,23,10,58,34,12,35,74,8,6,79,40,76,86,69,81,61,14,92,97,19,7,51,33,11,77,75,20,70,29,36,60,18,56,37,72,41,94,44,83,66,16,53 };
    
    vector<vector<vector<int>>> entirety;
    vector<vector<int>> board;
    int nums;
    
    // reading in the rows of bingo boards 
    for (int m = 0; m < 100; m++) {
        for (int j = 0; j < 5; j++) {
            vector<int> row;
            for (int i = 0; i < 5; i++) {
                input_file >> nums;
                row.push_back(nums);
            }
            board.push_back(row);
            row.clear(); // what an INCREDIBLE feature of vectors
        }
        entirety.push_back(board); // insert boards into huge umbrella vector 'entirety'
        board.clear();
    }
    
    // time to play !!!
  
    bool winning = false;
    int index = 0;
    
    vector<vector<vector<int>>> winner; // prep winning board
    
    while (not winning) {
        int curr_num = num[index]; // cycle through each calling number
        cout << "CURRENT NUM: " << curr_num << endl; // tracking purposes
        
        // if no. on board matches calling number, set to -1
        for (int i = 0; i < entirety.size(); i++) {
            for (int j = 0; j < entirety[i].size(); j++) {
                for (int k = 0; k < entirety[i][j].size(); k++) {
                    if (entirety[i][j][k] == curr_num) { 
                        entirety[i][j][k] = -1;
                    }
                }
            }
        }
        
        for (int i = 0; i < entirety.size(); i++) {
            for (int j = 0; j < entirety[i].size(); j++) {
                // checking for winning row/col
                if ((entirety[i][j][0] == -1 and entirety[i][j][1] == -1 and entirety[i][j][2] == -1 and entirety[i][j][3] == -1 and entirety[i][j][4] == -1) or (entirety[i][0][j] == -1 and entirety[i][1][j] == -1 and entirety[i][2][j] == -1 and entirety[i][3][j] == -1 and entirety[i][4][j] == -1)) {
                    winning = true;
                    cout << "FOUND A WINNER: " << curr_num << endl;
                    winner.push_back(entirety[i]); // winning board
                }
            }
        }
        index++;
    }
    
    // print out the numbers of the winning board;
    for (int i = 0; i < winner.size(); i++) {
        for (int j = 0; j < winner[i].size(); j++) {
            for (int k = 0; k < winner[i][j].size(); k++) {
                cout << winner[i][j][k] << endl;
            }
        }
    }
    
    // PART 2 CODE:
    
    // int winners = 0;
    
    // if no. of boards is not known, could also use entirety.size() > 1 ...
    // while (winners < 99) {
    //     int curr_num = num[index];
    //     cout << "CURRENT NUM: " << curr_num << endl;
    // 
    //     for (int i = 0; i < entirety.size(); i++) {
    //         for (int j = 0; j < entirety[i].size(); j++) {
    //             for (int k = 0; k < entirety[i][j].size(); k++) {
    //                 if (entirety[i][j][k] == curr_num) {
    //                     entirety[i][j][k] = -1;
    //                 }
    //             }
    //         }
    //     }
    // 
    //     for (int i = 0; i < entirety.size(); i++) {
    //         for (int j = 0; j < entirety[i].size(); j++) {
    //             if ((entirety[i][j][0] == -1 and entirety[i][j][1] == -1 and entirety[i][j][2] == -1 and entirety[i][j][3] == -1 and entirety[i][j][4] == -1) or (entirety[i][0][j] == -1 and entirety[i][1][j] == -1 and entirety[i][2][j] == -1 and entirety[i][3][j] == -1 and entirety[i][4][j] == -1)) {
    //                 winning = true;
    //                 cout << "FOUND A WINNER: " << curr_num << endl;
    //                 entirety[i].clear(); // DELET that board from vector
    //                 winners++; //
    //             }
    //         }
    //     }
    //     index++;
    // }
    // 
    // for (int i = 0; i < entirety.size(); i++) {
    //     for (int j = 0; j < entirety[i].size(); j++) {
    //         for (int k = 0; k < entirety[i][j].size(); k++) {
    //             cout << entirety[i][j][k] << endl;
    //         }
    //     }
    // }
    
    // MY FAILED CODE BEFORE I LEARNT ABOUT THE EXISTENCE OF VECTORS !!!
    
    // string num;
    // 
    // string bingo[5][5];
    // string current[5];
    // int full = 0;
    // int curr = 0;
    // 
    // input_file >> num;
    // 
    // for (int y = 0; y < 100; y++) {
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 5; j++) {
    //             input_file >> bingo[i][j];
    //         }
    //     }
    // 
    //     do {
    //         string temp = "";
    //         if (num[curr] == ',') {
    //             curr++;
    //         }
    //         if (num[curr] != ',') {
    //             temp += (num[curr]);
    //             curr++;
    //         }
    //         if (num[curr] != ',') {
    //             temp += (num[curr]);
    //             curr++;
    //         }
    //         current[full] = temp;
    //         full++;
    //     } while (full != 5);
    // 
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 5; j++) {
    //             for (int m = 0; m < 5; m++) {
    //                 if (bingo[i][j] == current[m]) {
    //                     bingo[i][j] = "taken";
    //                 }
    //             }
    //         }
    //     }
    // 
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 5; j++) {
    //             cout << bingo[i][j] << endl;
    //         }
    //     }
    // 
    //     full = 0;
    //     curr = 0;
    //     for (int i = 0; i < 5; i++) {
    //         current[i] = "";
    //     }
    // 
    //     int winner = 0;
    //     int counter = 0;
    // 
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 5; j++) {
    //             if (bingo[i][j] == "taken") {
    //                 counter++;
    //             }
    //         }
    //         cout << "COUNTER: " << counter << endl; 
    //         if (counter == 5) {
    //             winner++;
    //         }
    //         counter = 0;
    //     }
    // 
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 5; j++) {
    //             if (bingo[j][i] == "taken") {
    //                 counter++;
    //             }
    //         }
    //         cout << "COUNTER: " << counter << endl; 
    //         if (counter == 5) {
    //             winner++;
    //         }
    //         counter = 0;
    //     }
    // 
    //     cout << counter << endl;
    // 
    // }
    
    input_file.close();

    return 0;
}
