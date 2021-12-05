#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>

using namespace std;

// WITH MUCH HELP FROM ONE SHREYASRAVIOLI320, WHOSE PATIENCE AND GUIDANCE CARRIED ME THROUGH TODAY'S CHALLENGE.
// TODAY I LEARNED A LOT ABOUT MAPS. IT IS YET ANOTHER FANTASTIC CONCEPT.

// comments presented here are for personal learning!

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
    
    map<vector<int>, int> mp; 
    
    int x1p;
    int y1p;
    int x2p;
    int y2p;
    
    while (not input_file.eof()) {
      
        // reading in file
        input_file >> x1p;
        char c;
        input_file >> c;
        input_file >> y1p;
        string a;
        input_file >> a;
        input_file >> x2p;
        input_file >> c;
        input_file >> y2p;
        
        // checking horizontals
        if (y1p == y2p) {
            for (int i = min(x1p, x2p); i <= max(x1p, x2p); i++) {
                mp[{i,y1p}]++; // for each coordinate, add 1;
            }
        // checking verticals
        } else if (x1p == x2p) {
            for (int i = min(y1p, y2p); i <= max(y1p, y2p); i++) {
                mp[{x1p,i}]++; // for each coordinate, add 1;
            }
            // part 2
        } else if (abs(x1p-x2p) == abs(y1p-y2p)) { // slope needs to be 1, so y1p-y2p/x1p-x2p must == 1 or -1
            int dx = 1;
            int dy = 1;
            if (x2p < x1p) {
                dx = -1;
            }
            if (y2p < y1p) {
                dy = -1;
            }
            
            bool boolean = true;
            
            while (boolean) {
                mp[{x1p, y1p}]++;
                if (x1p == x2p and y2p == y1p) {
                    boolean = false;
                }
                x1p += dx;
                y1p += dy;
            }
        }
    }
    
    int count = 0;
    
    for (auto m : mp) // for each loop; auto is an "ambiguous type"; mp
    {
        if (m.second > 1) {
            count++;
        }
    }
    
    cout << count << endl;
    
    // DOOMED CODE GRAVEYARD
    
    // string x1;
    // string y1;
    // string x2;
    // string y2;
    // 
    // string arrow;
    // string line;
    // 
    // while(getline(input_file, line)) {
    //     stringstream ss(line);
    // 
    //     getline(ss, x1, ',');
    //     stringstream ph1(x1);
    //     int ph1x = 0;
    //     ph1 >> ph1x;
    //     sets.push_back(ph1x);
    // 
    //     getline(ss, y1, ' ');
    //     stringstream ph2(y1);
    //     int ph2y = 0;
    //     ph2 >> ph2y;
    //     sets.push_back(ph2y);
    // 
    //     getline(ss, arrow, ' ');
    // 
    //     getline(ss, x2, ',');
    //     stringstream ph3(x2);
    //     int ph3x = 0;
    //     ph3 >> ph3x;
    //     sets.push_back(ph3x);
    // 
    //     getline(ss, y2, ',');
    //     stringstream ph4(y2);
    //     int ph4y = 0;
    //     ph4 >> ph4y;
    //     sets.push_back(ph4y);
    // }
    
    // cout << *min_element(sets.begin(), sets.end()) << endl;
    // cout << *max_element(sets.begin(), sets.end()) << endl;
    // 
    // vector<vector<int>> board;
    // 
    // while (sets.size() > 1) {
    //     int x1s = sets[0];
    //     sets[0].erase();
    //     int y1s = sets[1];
    //     sets[1].erase();
    //     int x2s = sets[2];
    //     sets[2].erase();
    //     int y2s = sets[3];
    //     sets[3].erase();
    //     int diff_x = x2s - x1s;
    //     int diff_y = y2s - y1s;
    // }
    // 
    // maps;
    
    // cout << x1s << " " << y1s << " " << x2s << " " << y2s << " " << endl;
    
    // int lowest = 0;
    // int highest = 0;
    // 
    // for (int i = 0; i < sets.size() - 1; i++) {
    //     if (sets[i] < sets[i+1]) {
    //         lowest = sets[i];
    //         i++;
    //     } else if (sets[i] > sets[i+1]) {
    //         highest = sets[i];
    //         i++;
    //     }
    // }
    // 
    // cout << lowest << endl;
    // cout << highest << endl;
    
    // for (int i = 0; i < 4; i++) {
    //     istringstream iss(filename);
    //     int num = 0;
    //     if (iss.peek() == ',' or iss.peek() == '-' or iss.peek() == '>') {
    //         iss.ignore();
    //     }
    //     input_file >> num;
    //     sets.push_back(num);
    // }
    // 
    // for (int i = 0; i < 4; i++) {
    //     cout << sets[i] << endl;
    // }
    
    input_file.close();

    return 0;
}
