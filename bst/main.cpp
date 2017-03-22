// g++ -o main main.cpp bstree.cpp
// Coty Hamilton
// main.cpp

#include <iostream>
#include <string>
#include "bstree.h"

using namespace std;

int main()
{
    string status = "\n   an empty binary tree has been created";
    int option, key, retVal;
    Bstree tree;

    do
    {
        if (system( "cls" )) system( "clear" );
        tree.print2D();

        cout << "_________________________________________\n";
        cout << status << "\n\n";
        cout << " _______________________________________\n";
        cout << "|                                       |\n";
        cout << "|   (0) exit program                    |\n";
        cout << "|   (1) insert a node                   |\n";
        cout << "|   (2) delete a node                   |\n";
        cout << "|   (3) find predecessor of a node      |\n";
        cout << "|   (4) find successor of a node        |\n";
        cout << "|   (5) find depth of a node            |\n";
        cout << "|   (6) find height of a node           |\n";
        cout << "|   (7) find size of a subtree          |\n";
        cout << "|   (8) find minimum value in tree      |\n";
        cout << "|   (9) find maximum value in tree      |\n";
        cout << "|  (10) determine if tree is balanced   |\n";
        cout << "|_______________________________________|\n";

        cout << "   enter option number for operation: ";
        cin >> option;

        switch(option)
        {
            case 0: break;
            case 1: cout <<"\n   enter a value to insert: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        status = "\n   node already exists";
                    }
                    else
                    {
                        tree.insert(key);
                        status = "\n   " + to_string(key) + " was inserted";
                    }
                    break;
            case 2: cout <<"\n   enter the value of the node to deleted: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        tree.remove(key);
                        status = "\n   " + to_string(key) + " was deleted";
                    }
                    else
                    {
                        status = "\n   node does not exist";
                    }
                    break;
            case 3: cout <<"\n   enter the value of a node to find its predecessor: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        retVal = tree.predecessor(key);
                        status = "\n   predecessor of " + to_string(key) + " is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   node does not exist";
                    }
                    break;
            case 4: cout <<"\n   enter the value of a node to find its successor: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        retVal = tree.successor(key);
                        status = "\n   successor of " + to_string(key) + " is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   node does not exist";
                    }
                    break;
            case 5: cout <<"\n   enter the value of the node to find its depth: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        retVal = tree.depth(key);
                        status = "\n   depth of " + to_string(key) + " is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   node does not exist";
                    }
                    break;
            case 6: cout <<"\n   enter the value of the node to find its height: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        retVal = tree.height(key);
                        status = "\n   height of " + to_string(key) + " is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   node does not exist";
                    }
                    break;
            case 7: cout <<"\n   enter the value of a node to find its size: ";
                    cin >> key;
                    if (tree.search(key))
                    {
                        retVal = tree.size(key);
                        status = "\n   size of " + to_string(key) + " is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   node does not exist";
                    }
                    break;
            case 8: if (!tree.isEmpty())
                    {
                        retVal = tree.minimum();
                        status = "\n   minimum value in tree is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   tree is empty";
                    }
                    break;
            case 9: if (!tree.isEmpty())
                    {
                        retVal = tree.maximum();
                        status = "\n   maximum value in tree is " + to_string(retVal);
                    }
                    else
                    {
                        status = "\n   tree is empty";
                    }
                    break;
            case 10: if (!tree.isEmpty())
                    {
                        if(tree.isBalanced())
                        {
                            status = "\n   tree is balanced";
                        }
                        else
                        {
                            status = "\n   tree is not balanced";
                        }
                    }
                    else
                    {
                        status = "\n   tree is empty";
                    }
                    break;
        }
    }
    while(option != 0);

    return 0;
}
