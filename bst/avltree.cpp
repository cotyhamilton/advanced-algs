#include "avltree.h"
#include "bstree.h"

void Avltree::left_rotate(TreeNode* tree)
{
	TreeNode *x = tree;
	TreeNode *y = tree->right;

	y = x->right;
	x->right = y->left;
	if (y->left)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void Avltree::right_rotate(TreeNode* tree)
{
	TreeNode *x = tree;
	TreeNode *y = tree->left;

	y = x->left;
	x->left = y->right;
	if (y->right)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent)
	{
		root = y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right = y;
	}
	else
	{
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;

}
void Avltree::rebalance(TreeNode* tree)
{
	while (tree)
	{
		findHeight(tree);
		if (height(tree->left) >= 2 + height(tree->right))
		{
			if (height(tree->left->left) >= height(tree->left->right))
			{
				right_rotate(tree);
			}
			else
			{
				left_rotate(tree->left);
				right_rotate(tree);
			}
		}
		else if (height(tree->right) >= 2 + height(tree->left))
		{
			if (height(tree->right->right) >= height(tree->right->left))
			{
				left_rotate(tree);
			}
			else
			{
				right_rotate(tree->right);
				left_rotate(tree);
			}
		}
		tree = tree->parent;
	}
}

void Avltree::AVL_insert(int num)
{
	insert(num);
	rebalance(find(num));
	update();
}

void Avltree::AVL_remove(int num)
{
	TreeNode* par = find(num)->parent;
	remove(num);
	rebalance(par);
	update();
}
