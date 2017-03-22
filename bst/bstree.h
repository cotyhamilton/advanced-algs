#ifndef BSTREE_H
#define BSTREE_H

class Bstree 
{
    private:
        class TreeNode
        {
            friend class Bstree;
            int key;
            int height;
            int depth;
            int size;
            TreeNode *parent;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int num, TreeNode *p = NULL, TreeNode *lc = NULL, TreeNode *rc = NULL)
            {
                key = num;
                parent = p;
                left = lc;
                right = rc;
            }
        };
        TreeNode *root;

        void transplant(TreeNode *, TreeNode *);
        TreeNode* find(int);
        void findDepth(TreeNode *);
        int depth(TreeNode *);
        void findHeight(TreeNode*);
        int height(TreeNode *);
        void findSize(TreeNode *);
        int size(TreeNode *);
        TreeNode* minimum(int);
        TreeNode* maximum(int);
        void print2D(TreeNode *, int);
        int isBalanced(TreeNode *);
    public:
        Bstree()
        {
            root = NULL;
        }
        void insert(int);
        void remove(int);
        int predecessor(int);
        int successor(int);
        int depth(int);
        int height(int);
        int size(int);
        int minimum();
        int maximum();
        void print2D();
        bool isBalanced();
        bool search(int);
        bool isEmpty();
};

#endif