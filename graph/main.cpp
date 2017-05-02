// g++ -o main main.cpp graph.cpp

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

