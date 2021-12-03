#include <iostream>
#include <fstream>
#include <string> 
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
    
    // part 2, code written here is for co2 scrubber rating, VERY BAD but it WORKS
    
    string gamma[1000];
    string result;
    string counter_result;
    
    for (int i = 0; i < 1000; i++) {
        input_file >> gamma[i];
    }

    string ones[1000];
    string zeroes[1000];
    string filtered[1000];
    
    for (int i = 0; i < 1000; i++) {
        ones[i] = ""; // initialise arrays with empty strings, helpful later
        zeroes[i] = "";
        filtered[i] = gamma[i];
    }
    
    int len = 1000;
    int refresh_len = 0;
    int counter0 = 0, counter1 = 0;

    for (int k = 0; k < 8; k++) { // terrible trial and error
        cout << len << endl; // check length of filtered array at every loop
        for (int j = 0; j < len; j++) {
            string current = filtered[j];
            if (current[k] == '0') {
                zeroes[counter0] = current;
                counter0++;
            } else if (current[k] == '1'){
                ones[counter1] = current;
                counter1++;
            }
        }
        cout << counter0 << " " << counter1 << endl; // compare amounts of 0 & 1
        if (counter0 > counter1) { // change depending on oxygen vs co2 rating
            for (int i = 0; i < len; i++) {
                filtered[i] = ""; // clean up filtered array
                filtered[i] = ones[i]; // introduce new values
            }
        } else if (counter0 <= counter1){
            for (int i = 0; i < len; i++) {
                filtered[i] = "";
                filtered[i] = zeroes[i];
            }
        }
        for (int i = 0; i < 1000; i++) {
            ones[i] = ""; // clean up ones and zeroes array
            zeroes[i] = "";
            if (filtered[i] != "") {
                refresh_len++; // refresh length of array
            }
        }
        len = refresh_len; // update len to new len
        refresh_len = 0; // set everything back to zero for new loop
        counter0 = 0;
        counter1 = 0;
    }
    
    cout << filtered[0] << endl; // hopefully it all works
    
    //001100001101
    //101010101110
    
    input_file.close(); // i am going to bed it is 2:01am now

    return 0;
}
