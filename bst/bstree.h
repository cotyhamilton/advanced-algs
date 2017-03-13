#ifndef bstree_h
#define bstree_h

class Bstree 
{
    private:
        struct TreeNode
        {
            int key;
            int height;
            int depth;
            int size;
            TreeNode *parent;
            TreeNode *leftChild;
            TreeNode *rightChild;

            TreeNode(int k; TreeNode *p, TreeNode *lc, TreeNode *rc);
            ~TreeNode();
        }
        TreeNode *root;
    public:
        Bstree();
        ~Bstree();
        void insert(int x);
        void delete(TreeNode *x);
        TreeNode predecessor(TreeNode *x);
        TreeNode successor(TreeNode *x);
        int height(TreeNode *x);
        TreeNode search(int x);
        TreeNode minimum(TreeNode *x);
        TreeNode maximum(TreeNode *x);
        void print2D();
        void findDepth();
        void findHeight();
        void findSize();
        bool isBalanced();
}

#endif