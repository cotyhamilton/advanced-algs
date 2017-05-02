#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <stack>
#include <queue>

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
    
    int matrix[6][6] = {
                {0,1,1,1,0,0},
                {1,0,0,0,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,0},
                {0,1,0,0,0,0},
                {0,1,1,0,0,0}
            };
    Node* list[6];

    std::queue<char> Q;
    std::stack<char> S;


    void BFSp();
    void DFSp();
    void reset();
public:
    void BFS();
    void DFS();
    Graph()
    {
        list[0] = new Node('A',0);
        list[1] = new Node('B',1);
        list[2] = new Node('C',2);
        list[3] = new Node('D',3);
        list[4] = new Node('E',4);
        list[5] = new Node('F',5);
    }
};

#endif