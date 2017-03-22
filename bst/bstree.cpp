#include <iostream>
#include <algorithm>
#include <cmath>
#include "bstree.h"
#define COUNT 10

void Bstree::transplant(TreeNode *node1, TreeNode *node2)
{
    if (!node1->parent)
    {
        root = node2;
    }
    else if (node1 == node1->parent->left)
    //if the node to be deleted is the left child of its parent make
    //the replacement node the left child of deleted node's parent 
    {
        node1->parent->left = node2;
    }
    else
    {
        node1->parent->right = node2;
    }
    if (node2)
    //link replacement node to its parent
    {
        node2->parent = node1->parent;
    }
}

Bstree::TreeNode* Bstree::find(int num)
{
    TreeNode *tree = root;

    while (tree->key != num)
    {
        if (num < tree->key)
        {
            tree = tree->left;
        }
        else
        {
            tree = tree->right;
        }
    }

    return tree;
}

void Bstree::findDepth(TreeNode* tree)
{
    if(tree)
    {
        findDepth(tree->left);
        tree->depth = depth(tree);
        findDepth(tree->right);
    }
}

int Bstree::depth(int num)
{
    return (find(num))->depth;
}

int Bstree::depth(TreeNode* tree)
{
    if (!tree)
    {
        return -1;
    }
    else
    {
        return 1 + depth(tree->parent);
    }
}

void Bstree::findHeight(TreeNode *tree)
{
    if(tree)
    {
        findHeight(tree->left);
        tree->height = height(tree);
        findHeight(tree->right);
    }
}

int Bstree::height(TreeNode *tree)
{
    if(!tree)
    {
        return -1;
    }
    return 1 + std::max(height(tree->left), height(tree->right));
}

void Bstree::findSize(TreeNode* tree)
{
    if(tree)
    {
        findSize(tree->left);
        tree->size = size(tree);
        findSize(tree->right);
    }
}

int Bstree::size(TreeNode* tree)
{
    if (!tree)
    {
        return 0;
    }
    else
    {
        return 1 + (size(tree->left) + size(tree->right));
    }
    
}

Bstree::TreeNode* Bstree::minimum(int num)
{
    TreeNode *tree = find(num);

    while (tree->left)
    {
        tree = tree->left;
    }

    return tree;
}

Bstree::TreeNode* Bstree::maximum(int num)
{
    TreeNode *tree = find(num);

    while (tree->right)
    {
        tree = tree->right;
    }
    
    return tree;
}

void Bstree::print2D(TreeNode *tree, int space)
{
    if(!tree)
    {
        return;
    }
    space += COUNT;

    print2D(tree->right, space);

    for (int i = COUNT; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << tree->key << std::endl;

    print2D(tree->left, space);
}

int Bstree::isBalanced(TreeNode *tree)
{
    if (!tree)
    {
        return 0;
    }
    if (std::abs(tree->left->height - tree->right->height) > 1 )
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Bstree::insert(int num)
{
    if (!root)
    //if root is null create root node
    {
        root = new TreeNode(num);
    }
    else
    {
        TreeNode *tree = root;
        TreeNode *newParent = NULL;
        //trailing pointer
        TreeNode *newNode = new TreeNode(num);

        while (tree)
        {
            newParent = tree;
            if (newNode->key == tree->key)
            //if node with value to insert already exists, delete new node and return
            {
                delete newNode;
                return;
            }
            else if (newNode->key < tree->key)
            {
                tree = tree->left;
            }
            else
            {
                tree = tree->right;
            }
        }

        newNode->parent = newParent;

        if (newNode->key < newParent->key)
        {
            newParent->left = newNode;
        }
        else
        {
            newParent->right = newNode;
        }
    }
    findHeight(root);
    findDepth(root);
    findSize(root);
}

void Bstree::remove(int num)
{
    TreeNode *tree = find(num);

    //tree is now the node to be deleted
    if (!tree->left)
    {
        transplant(tree, tree->right);
    }
    else if (!tree->right)
    {
        transplant(tree, tree->left);
    }
    else
    {
        TreeNode *succ = minimum(tree->right->key);
        if (succ->parent != tree)
        {
            transplant(succ, succ->right);
            succ->right = tree->right;
            succ->right->parent = succ;
        }
        transplant(tree, succ);
        succ->left = tree->left;
        succ->left->parent = succ;
    }
    findHeight(root);
    findDepth(root);
    findSize(root);
}

int Bstree::predecessor(int num)
{
    TreeNode *tree = find(num);

    //if the node has a left child return
    //the smallest value in the right subtree
    if (tree->left)
    {
        return (maximum(tree->left->key))->key;
    }

    while(tree->parent->left == tree)
    {
        tree = tree->parent;
    }
    return tree->parent->key;
}

int Bstree::successor(int num)
{
    TreeNode *tree = find(num);

    //if the node has a right child return
    //the smallest value in the right subtree
    if (tree->right)
    {
        return (minimum(tree->right->key))->key;
    }

    while(tree->parent->right == tree)
    {
        tree = tree->parent;
    }
    return tree->parent->key;
}

int Bstree::height(int num)
{
    return (find(num))->height;
}

int Bstree::size(int num)
{
    return (find(num))->size;
}

int Bstree::minimum()
{
    TreeNode *tree = root;
    if (!tree)
    {
        return -1;
    }
    while (tree->left)
    {
        tree = tree->left;
    }
    return tree->key;
}

int Bstree::maximum()
{
    TreeNode *tree = root;
    if(!tree)
    {
        return -1;
    }
    while (tree->right)
    {
        tree = tree->right;
    }
    return tree->key;
}

void Bstree::print2D()
{
    print2D(root, 0);
}

bool Bstree::isBalanced()
{
    int num = isBalanced(root);

    if (num < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Bstree::search(int num)
{
    TreeNode *tree = root;

    while (tree)
    {
        if (tree->key == num)
        {
            return true;
        }
        else if (num < tree->key)
        {
            tree = tree->left;
        }
        else
        {
            tree = tree->right;
        }
    }
    return false;
}

bool Bstree::isEmpty()
{
    if(!root)
    {
        return true;
    }
    else
    {
        return false;
    }
}