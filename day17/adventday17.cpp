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
    
    // target area: x=57..116, y=-198..-148
    
    // lol manual input... feelsbad
    int x1 = 57;
    int x2 = 116;
    int y1 = -198;
    int y2 = -148;
    
    // int x1 = 20;
    // int x2 = 30;
    // int y1 = -10;
    // int y2 = -5;
    
    int x_target = 0;
    int y_target = 0;
    int max_height = 0;
    vector<int> max_heights;
  
    int valid_velocities = 0;
  
    // pretty simple. still took me some thinking through sleep though.
    // not gonna deluge this with comments, i think its pretty easy to follow
    
    for (int i = 0; i < 117; i++) { // kind of guessing the bounds here. x2 + 1? 
        for (int j = -199; j < 199; j++) { // same here... 
    
            bool valid = true;
            int x = i, y = j;
            int x_initial = x, y_initial = y;
            
            while (x_target > x2 
                or x_target < x1
                or y_target > y2 
                or y_target < y1) 
            {
                x_target += x;
                y_target += y;
                
                if (y_target > max_height) {
                    max_height = y_target;
                }
                
                if (x > 0) {
                    x--;
                }
                y--;
                
                if (y_target < y1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                valid_velocities++;
                cout << "INITIAL VELOCITY -> " << x_initial << " : " << y_initial << endl;
                cout << "FINAL POS -> " << x_target << " : " << y_target << endl;
                cout << "MAX HEIGHT -> " << max_height << endl << endl;
                max_heights.push_back(max_height);
            }
            
            max_height = 0;
            y_target = 0;
            x_target = 0;
            
        }
    }
    
    int max = *max_element(max_heights.begin(), max_heights.end());
    cout << "FINAL MAX HEIGHT: " << max << endl;
    
    cout << valid_velocities << endl;
    
    return 0;
}
