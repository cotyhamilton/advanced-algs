#ifndef GRAPH_H
#define GRAPH_H

#include <string>

class Graph
{
private:
    struct Node
    {
        int index;
        char name;
        Node *p;
        int d, f;
        std::string color;
        Node(char n, int i)
        {
            name = n;
            index = i;
            p = NULL;
            d = 0;
            f = 0;
            color = "white";
        }
    };
    
    int (*matrix)[6];
    Node* (*list)[6];
    void BFSp();
public:
    void BFS();
    void DFS();
    Graph()
    {
        int a[6][6] = {
                {0,1,1,1,0,0},
                {1,0,0,0,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,0},
                {0,1,0,0,0,0},
                {0,1,1,0,0,0}
            };
        matrix = a;
        Node *A = new Node('A',0);
        Node *B = new Node('B',1);
        Node *C = new Node('C',2);
        Node *D = new Node('D',3);
        Node *E = new Node('E',4);
        Node *F = new Node('F',5);
        Node* ar[6] = {A,B,C,D,E,F};
        list = &ar;
    }
};

#endif