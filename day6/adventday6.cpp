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
    
    // part 1, the calm before the exponential storm
    
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
    
    map<int, long long> mp;
    
    while (not input_file.eof()) {
        char c;
        long long curr;
        input_file >> curr;
        input_file >> c;
        mp[curr]++;
    }
    
    for (int i = 0; i < 256; i++) {
        long long add = mp[0]; 
        mp[0] = mp[1];
        mp[1] = mp[2];
        mp[2] = mp[3];
        mp[3] = mp[4];
        mp[4] = mp[5];
        mp[5] = mp[6];
        mp[6] = add + mp[7];
        mp[7] = mp[8];
        mp[8] = add; 
    }
    
    long long ans = 0;
    
    for (auto m : mp) {
        ans += m.second;
    }
    
    cout << ans << endl;

    return 0;
}
