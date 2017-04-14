#ifndef AVLTREE_H
#define AVLTREE_H

#include "bstree.h"

class Avltree : public Bstree
{
private:
	void left_rotate(TreeNode *);
	void right_rotate(TreeNode *);
	void rebalance(TreeNode *);
public:
	void AVL_insert(int);
	void AVL_remove(int);
};






#endif