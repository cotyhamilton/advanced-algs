// Coty Hamilton

// g++ -o main main.cpp graph.cpp -std=c++11


#include <iostream>
#include "graph.h"

// #define SIZE 4

using namespace std;

// void print(int (*)[SIZE]);

int main() {

    Graph graph;

    graph.BFS();
    graph.DFS();

    return 0;
}

