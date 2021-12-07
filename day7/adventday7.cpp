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
  
    // today was pretty easy. i'm not in a good mood so i don't have much to say. goodnight!
    
    vector<long long> crabs;
    
    while (not input_file.eof()) {
        char c;
        long long curr;
        input_file >> curr;
        input_file >> c;
        crabs.push_back(curr);
    }
    
    double max = *max_element(crabs.begin(), crabs.end());
    double min = *min_element(crabs.begin(), crabs.end());
    
    cout << max << endl;
    cout << min << endl;
    
    vector<long> s; // vector of sums
    
    long sum = 0;
    
    for (int i = min; i < max; i++) {
        for (int j = 0; j < crabs.size(); j++) {
            // part 1:
            // sum += abs(crabs[j] - i)
          
            // part 2:
            int diff = abs(crabs[j] - i);
            for (int m = 1; m < diff + 1; m++) {
                sum += m;
            }
        }
        s.push_back(sum);
        sum = 0;
    }
    
    double min_sum = *min_element(s.begin(), s.end()); // find smallest sum i.e. smallest distances
    
    cout << min_sum << endl;

    return 0;
}
