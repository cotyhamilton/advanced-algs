#include <iostream>
#include "bstree.h"

void Bstree::insert(TreeNode *&tree, int num)
{
    // function is passed a reference to a pointer because
    // it may need to be modified by function

    // base case
    // if the tree is empty, make a new node and make it
    // the root of the tree
    if (!tree)
    {
        tree = new TreeNode(num);
        return;
    }
    // if num is already in tree: return
    if (tree->key == num)
    {
        return;
    }
    // tree is not empty: insert new node into the
    // left or right subtree
    if (num < tree->key)
    {
        insert(tree->left, num);
    }
    else
    {
        insert(tree->right, num);
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

void Bstree::destroySubtree(TreeNode *tree)
{
    if (!tree) return;
    destroySubtree(tree->left);
    destroySubtree(tree->right);
    // delete root node
    delete tree;
}

void Bstree::remove(TreeNode *&tree, int num)
{
    if(tree == NULL) return;
    if(num < tree->key)
    {
        remove(tree->left, num);
    }
    else if (num > tree->key)
    {
        remove(tree->right, num);
    }
    else
    {
        makeDeletion(tree);
    }
}

void Bstree::makeDeletion(TreeNode *&tree)
{
    TreeNode *nodeToDelete = tree;
    TreeNode *attachPoint;

    if (tree->right == NULL)
    {
        tree = tree->left;
    }
    else if (tree->left == NULL)
    {
        tree = tree->right;
    }
    else
    {
        attachPoint = tree->right;

        while(attachPoint->left != NULL)
        {
            attachPoint = attachPoint->left;
        }
        attachPoint->left = tree->left;
        tree = tree->right;
    }
    delete nodeToDelete;
}

void Bstree::displayInOrder(TreeNode *tree)
{
    if(tree)
    {
        displayInOrder(tree->left);
        std::cout << tree->key << " ";
        displayInOrder(tree->right);
    }
}

void Bstree::displayPreOrder(TreeNode *tree)
{
    if(tree)
    {
        std::cout << tree->key << " ";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}

void Bstree::displayPostOrder(TreeNode *tree)
{
    if(tree)
    {
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
        std::cout << tree->key << " ";
    }
}

void Bstree::insert(int num)
{
    insert(root, num);
}

void Bstree::remove(int num)
{
    remove(root, num);
}

// TreeNode Bstree::predecessor(TreeNode *x)
// {

// }

// TreeNode Bstree::successor(TreeNode *x)
// {

// }

// int Bstree::height(TreeNode *x)
// {

// }


// TreeNode Bstree::minimum(TreeNode *x)
// {

// }

// TreeNode Bstree::maximum(TreeNode *x)
// {

// }

// void Bstree::print2D()
// {

// }

// void Bstree::findDepth()
// {

// }

// void Bstree::findHeight()
// {

// }

// void Bstree::findSize()
// {

// }

// bool Bstree::isBalanced()
// {
    
// }

void Bstree::showInOrder()
{
    displayInOrder(root);
}
void Bstree::showPreOrder()
{
    displayPreOrder(root);
}

void Bstree::showPostOrder()
{
    displayPostOrder(root);
}