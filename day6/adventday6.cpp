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
    
    // Today was an application of maps! solved part 1 without much of a hitch... already using the vectors I just learned about 2 days back...
    
    // part 1, the calm before the exponential storm...
    
    // vector<long long> fish;
    // 
    // while (not input_file.eof()) {
    //     char c;
    //     long long curr;
    //     input_file >> curr;
    //     input_file >> c;
    //     fish.push_back(curr);
    // }
    // 
    // for (int i = 0; i < 18; i++) {
    //     for (int i = 0; i < fish.size(); i++) {
    //         if (fish[i] == 0) {
    //             fish[i] = 6;
    //             fish.push_back(9);
    //         } else {
    //             fish[i]--;
    //         }
    //     }
    // }
    // 
    // long long sum = 0;
    // 
    // for (long long m : fish) {
    //     sum++;
    // }
    
    // part 2, using maps in the framework of u/FqdingSky's code
    
    map<int, long long> mp; // using maps to keep track of how many fishes with a life span of [0,8] currently exist
    
    while (not input_file.eof()) {
        char c;
        long long curr;
        input_file >> curr;
        input_file >> c;
        mp[curr]++; // add fishes according to their current lifespan
    }
    
    // this is brilliant...
    for (int i = 0; i < 256; i++) {
        long long add = mp[0]; 
        mp[0] = mp[1]; // cascading; all fishes with lifespan n+1 become fishes with lifespan n
        mp[1] = mp[2];
        mp[2] = mp[3];
        mp[3] = mp[4];
        mp[4] = mp[5];
        mp[5] = mp[6];
        mp[6] = add + mp[7]; // all the 0s turn into 6s, as do the 7s
        mp[7] = mp[8];
        mp[8] = add; // all the 0s spawn 8s
        // mp[6] and mp[8] are where most of the additions occur
    }
    
    long long ans = 0;
    
    for (auto m : mp) {
        ans += m.second; // add fishes with lifespan of 0 through 8 after 256 days (m.second accesses value of keys in maps)
    }
    
    cout << ans << endl; // bingo bango bongo

    return 0;
}
