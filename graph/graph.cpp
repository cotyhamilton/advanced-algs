// Coty Hamilton

#include <iostream>
#include <typeinfo>
#include "graph.h"

void Graph::BFSp()
{
    Q.push(0);
    while (!Q.empty())
    {
        int current = Q.front();

        for (int i = 0; i < 6; i++)
        {
            if (matrix[current][i])
            {
                if (list[i]->color == "white")
                {
                    list[i]->color = "grey";
                    Q.push(i);
                    
                }
            }
        }
        std::cout << list[Q.front()]->name;
        list[Q.front()]->color = "black";
        Q.pop();
    }
}

void Graph::DFSp()
{
    S.push(0);
    std::cout << list[0]->name;
    list[0]->color = "grey";
    while (!S.empty())
    {
        int current = S.top();
        int i = 0;
        while(i < 6)
        {
            if (matrix[current][i] && list[i]->color == "white")
            {
                std::cout << list[i]->name;
                list[i]->color = "gray";
                S.push(i);
                break;
            }
            i++;
        }
        if (i == 6)
        {
            S.pop();
        }
    }

}

void Graph::reset()
{
    for (int i = 0; i < 6; i++)
    {
        list[i]->color = "white";
    }
}

void Graph::BFS()
{
    std::cout << "BFS results: \n";
    BFSp();
    std::cout << std::endl;
    reset();
}

void Graph::DFS()
{
    std::cout << "DFS results: \n";
    DFSp();
    std::cout << std::endl;
    reset();
}