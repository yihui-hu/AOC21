#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

int binaryToDecimal(int n);
int roundUp(int numToRound, int multiple);
int get_version_id(ifstream &input_file, vector<int> &versions, 
                   vector<int> &ids);
void id4(ifstream &input_file, vector<string> &bits_v);
int id4_counter(ifstream &input_file, vector<string> &bits_v);
int other_id(ifstream &input_file, vector<string> &bits_v, vector<int> &versions, vector<int> &ids, int max_counter);

// i am probably not going to be able to solve this anytime soon but here is what i have thus far. lots of recursion happening, makes my brain hurt. sad

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
    
    int curr_id = 0;
    vector<int> versions;
    vector<int> ids;
    vector<string> bits_v;
    int temp = 0;
    int max_counter = 0;
    
    while (not input_file.eof()) {
        curr_id = get_version_id(input_file, versions, ids);
        
        if (curr_id == 4) {
            id4(input_file, bits_v);
        } else {
            temp = other_id(input_file, bits_v, versions, ids, max_counter);
        }
        
        while (not input_file.eof()) {
            char trash;
            input_file >> trash;
        }
    }
    
    cout << "Bits:" << endl;
    for (string m : bits_v) {
        cout << m << ", ";
    }
    cout << endl << endl;
    
    cout << "Versions:" << endl;
    for (int m : versions) {
        cout << m << ", ";
    }
    cout << endl << endl;
    
    cout << "IDs:" << endl;
    for (int m : ids) {
        cout << m << ", ";
    }
    cout << endl << endl;
    
    return 0;
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int get_version_id(ifstream &input_file, vector<int> &versions, vector<int> &ids) {
    char temp;
    
    int version_no;
    int id_no;
    
    string version;
    string id;
    
    for (int i = 0; i < 3; i++) {
        input_file >> temp;
        version += temp;
    }
    version_no = binaryToDecimal(stoi(version));
    versions.push_back(version_no);

    for (int i = 0; i < 3; i++) {
        input_file >> temp;
        id += temp;
    }
    id_no = binaryToDecimal(stoi(id));
    ids.push_back(id_no);
    
    // cout << "Version No: " << version_no << endl;
    // cout << "ID No: " << id_no << endl;
    
    return id_no;
}

int id4_counter(ifstream &input_file, vector<string> &bits_v) {
    char temp;
    string bits;
    int counter = 0;
    input_file >> temp;
    counter++;
    
    while (temp != '0') {
        char bit;
        for (int i = 0; i < 4; i++) {
            input_file >> bit;
            bits += bit;
            counter++;
        }
        input_file >> temp;
        counter++;
    }
    
    char bit0;
    for (int i = 0; i < 4; i++) {
        input_file >> bit0;
        bits += bit0;
        counter++;
    }
    
    bits_v.push_back(bits);
    
    return counter;
}

void id4(ifstream &input_file, vector<string> &bits_v) {
    char temp;
    input_file >> temp;
    
    while (temp != '0') {
        char bit;
        string bits;
        for (int i = 0; i < 4; i++) {
            input_file >> bit;
            bits += bit;
        }
        bits_v.push_back(bits);
        input_file >> temp;
    }
    
    char bit0;
    string bits0;
    for (int i = 0; i < 4; i++) {
        input_file >> bit0;
        bits0 += bit0;
    }
    bits_v.push_back(bits0);
}

int other_id(ifstream &input_file, vector<string> &bits_v, vector<int> &versions, vector<int> &ids, int max_counter, int length) {
    int curr_id;
    char temp;
    input_file >> temp;
    max_counter++;
    
    if (temp == '0') {
        char bit15;
        string bit_15;
        int length;
    
        for (int i = 0; i < 15; i++) {
            input_file >> bit15;
            max_counter++;
            bit_15 += bit15;
        }
        cout << "BIT: " << bit_15 << endl;
        length = binaryToDecimal(stoi(bit_15));
        cout << "LENGTH: " << length << endl;
        
        int counter = 0;
        while (counter < length) {
            curr_id = get_version_id(input_file, versions, ids);
            counter += 6;
            if (curr_id == 4) {
                counter += id4_counter(input_file, bits_v);
            } else {
                counter += other_id(input_file, bits_v, versions, ids, max_counter);
            }
        }
        max_counter += counter;
    
    } else {
        char bit11;
        string bit_11;
        int subpacket_no;
    
        for (int i = 0; i < 11; i++) {
            input_file >> bit11;
            max_counter++;
            bit_11 += bit11;
        }
        subpacket_no = binaryToDecimal(stoi(bit_11));
        
        for (int i = 0; i < subpacket_no; i++) {
            curr_id = get_version_id(input_file, versions, ids);
            max_counter += 6;
            if (curr_id == 4) {
                max_counter += id4_counter(input_file, bits_v);
            } else {
                max_counter += other_id(input_file, bits_v, versions, ids, max_counter);
            }
        }
    }
    
    return max_counter;
}
