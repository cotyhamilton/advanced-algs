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

        void insert(TreeNode *&, int);
        void destroySubtree(TreeNode *);
        void remove(TreeNode *&, int);
        void makeDeletion(TreeNode *&);
        void displayInOrder(TreeNode *);
        void displayPreOrder(TreeNode *);
        void displayPostOrder(TreeNode *);
    public:
        Bstree()
        {
            root = NULL;
        }

        ~Bstree()
        {
            destroySubtree(root);
        }

        void insert(int);
        void remove(int);
        // TreeNode predecessor(TreeNode *);
        // TreeNode successor(TreeNode *);
        // int height(TreeNode *);
        bool search(int);
        // TreeNode minimum(TreeNode *);
        // TreeNode maximum(TreeNode *);
        // void print2D();
        // void findDepth();
        // void findHeight();
        // void findSize();
        // bool isBalanced();
        void showInOrder(void);
        void showPreOrder();
        void showPostOrder();
};

#endif