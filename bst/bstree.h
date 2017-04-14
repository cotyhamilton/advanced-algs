// Coty Hamilton
// bstree.h

#ifndef BSTREE_H
#define BSTREE_H

class TreeNode
{
	friend class Bstree;
	friend class Avltree;
	int key;
	int height;
	int depth;
	int size;
	int balance;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int num, TreeNode *p = 0, TreeNode *lc = 0, TreeNode *rc = 0)
	{
		key = num;
		parent = p;
		left = lc;
		right = rc;
	}
};

class Bstree
{
	friend class Avltree;
	TreeNode *root;
	void transplant(TreeNode *, TreeNode *);
	TreeNode* find(int);
	void findDepth(TreeNode *);
	int depth(TreeNode *);
	void findHeight(TreeNode*);
	int height(TreeNode *);
	void findSize(TreeNode *);
	int size(TreeNode *);
	void findBalanceFactor(TreeNode *);
	int balanceFactor(TreeNode *);
	TreeNode* minimum(int);
	TreeNode* maximum(int);
	void print2D(TreeNode *, int);
	int isBalanced(TreeNode *);
public:
	Bstree()
	{
		root = 0;
	}
	void insert(int);
	void remove(int);
	int predecessor(int);
	int successor(int);
	int depth(int);
	int height(int);
	int size(int);
	int balanceFactor(int);
	int minimum();
	int maximum();
	void print2D();
	bool isBalanced();
	bool search(int);
	bool isEmpty();
	void update();
};

#endif
