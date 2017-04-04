#ifndef AVLTREE_H
#define AVLTREE_H

class Avltree : public Bstree
{
    private:
        void AVL_insert(TreeNode *);
        void AVL_remove(TreeNode *);
        void left_rotate(TreeNode *);
        void right_rotate(TreeNode *);
        void rebalance(TreeNode *);
    public:
        void AVL_insert(int x);
        void AVL_remove(int x);
};






#endif