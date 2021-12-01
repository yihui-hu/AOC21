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
    
    // contingent on knowing the length of input file...
    // an arraylist is better 
    int depths[2000];
    
    for (int i = 0; i < 2000; i++) {
        input_file >> depths[i];
    }
    
    int counter = 0;
    
    // for part 1
    //
    // for (int j = 0; j < 2000; j++) {
    //     if (j < 1999) {
    //         if (depths[j] < depths[j+1]) {
    //             counter++;
    //         }
    //     }
    // }
    
    for (int j = 0; j < 2000; j++) {
        if (j < 1997) {
            int sum1 = depths[j] + depths[j+1] + depths[j+2];
            int sum2 = depths[j+1] + depths[j+2] + depths[j+3];
            if (sum2 > sum1) {
                counter++;
            }
        }
    }
    
    cout << counter << endl;
    
    input_file.close();

    return 0;
}