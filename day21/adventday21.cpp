#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

void play_turn(int *player, int *dice, int *score, int *rolls);

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
  
    // simpler than the past few days. only part 1 though. and some ugly code. had to refresh myself on pointers...
    // did the best i could cleaning up. i'm busy with other projects now :)
    
    int p1 = 4;
    int p1_score = 0;
    int p2 = 8;
    int p2_score = 0;
    
    int turn = 1; // p1 plays on -1, p2 plays on 1
    
    int dice = 0;
    int rolls = 0;
    
    while (p1_score < 1000 and p2_score < 1000) {
        if (turn > 0) {
            play_turn(&p1, &dice, &p1_score, &rolls);
        } else {
            play_turn(&p2, &dice, &p2_score, &rolls);
        }
        turn *= -1;
    }
    
    cout << "P1 SCORE: " << p1_score << endl;
    cout << "P2 SCORE: " << p2_score << endl;
    cout << "ROLLS: " << rolls << endl;
    
    return 0;
}

void play_turn(int *player, int *dice, int *score, int *rolls) {
    int pos = *player;
    int dice_roll = *dice;
    
    for (int i = 0; i < 3; i++) {
        if (dice_roll == 100) {
            dice_roll = 0;
        }
        dice_roll = dice_roll + 1;
        pos += dice_roll;
        if (pos > 10) {
            pos = pos % 10;
            if (pos == 0) {
                pos = 10;
            }
        }
    }
    
    *player = pos;
    *dice = dice_roll;
    *rolls += 3;
    *score += *player;
}
