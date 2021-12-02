#include <iostream>
#include <fstream>

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
    
    // part 2
    
    int horizontal_pos = 0;
    int depth = 0;
    int aim = 0;
    
    for (int i = 0; i < 1000; i++) {
        string direction;
        int amount;
        input_file >> direction;
        input_file >> amount;
        
        if (direction == "forward") {
            horizontal_pos += amount;
            depth += (aim * amount);
        } else if (direction == "up") {
            aim -= amount; 
        } else if (direction == "down") {
            aim += amount;
        }    
    }
    
    cout << horizontal_pos * depth << endl;
    
    // // part 1
    // 
    // int horizontal_pos = 0;
    // int depth = 0;
    // 
    // for (int i = 0; i < 1000; i++) {
    //     string direction;
    //     int amount;
    //     input_file >> direction;
    //     input_file >> amount;
    // 
    //     if (direction == "forward") {
    //         horizontal_pos += amount;
    //     } else if (direction == "up") {
    //         depth -= amount; 
    //     } else if (direction == "down") {
    //         depth += amount;
    //     }    
    // }
    // 
    // cout << horizontal_pos * depth << endl;
    
    input_file.close();

    return 0;
}
