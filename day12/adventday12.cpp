#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <deque>

using namespace std;

class Graph { 
    int V;
    list<string> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<string>[V];
    }

    void addEdge(string x, string y) {
        for (int i = 0; i < l->size(); i++) {
            if (l[i] == x) {
                l[i].push_back(y);
            } else if (l[i] == y) {
                l[i].push_back(x);
            }
        }
    }
};

// UNSUCCESSFUL!!!
// WILL REVISIT THIS PUZZLE AFTER FINALS. AFTER I HAVE LEARNED ABOUT GRAPHS.

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
    
    ifstream f("advent12.txt");
    // dc-end
    // HN-start
    // start-kj
    // dc-start
    // dc-HN
    // LN-dc
    // HN-end
    // kj-sa
    // kj-HN
    // kj-dc
    
    Graph g(7);
    g.addEdge("dc", "end");
    g.addEdge("HN", "start");
    g.addEdge("start", "kj");
    g.addEdge("dc", "start");
    g.addEdge("dc", "HN");
    g.addEdge("LN", "dc");
    g.addEdge("HN", "end");
    g.addEdge("kj", "sa");
    g.addEdge("kj", "HN");
    g.addEdge("kj", "dc");
    
    // vector<string> vertex(0);
    // string in;
    // 
    // for (int i = 0; i < 10; i++) {
    //     string one;
    //     string two;
    //     string in;
    //     int counter = 0;
    //     input_file >> in;
    // 
    //     for (int j = 0; j < in.length(); j++) {
    //         if (in[j] == '-') {
    //             counter++;
    //             continue;
    //         }
    //         if (counter == 0) {
    //             one += in[j];
    //         } else {
    //             two += in[j];
    //         }
    //     }
    // 
    //     g.addEdge(one, two);
    // }
    
    // for (string m : vertex) {
    //     cout << m << endl;
    // }
    
    return 0;
}
