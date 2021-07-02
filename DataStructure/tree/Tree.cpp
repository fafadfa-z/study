#include<stdlib.h>
#include<stdio.h>

#include<iostream>
#include<queue>   // 不想自己实现优先队列，先用自带的凑合吧

#include"tree.h"


void Tree::treeBuild(const vector<int>&nums)
{
	for (auto i : nums)
	{






	}
}

void Tree::insert(const int x, TreeNode*& t)
{
	if (t == nullptr) t = new TreeNode(x);    // 如果走到头了，就新开一片空间，将它插入到这

	else if (x < t->value)    // 往左子树上插
	{
		insert(x,t->left);


		if (height(t->left) - height(t->right) == 2)
			if (x < t->left->value)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
	}
	else if (x > t->value)
	{
		insert(x, t->right);
		if (height(t->left) - height(t->right) == -2)
			if (x < t->left->value)
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
	}

	t->high = height(t->left)> height(t->right)? height(t->left)+1: height(t->right)+1;// 这玩意一定要在旋转之后再计算

}
void Tree::rotateWithLeftChild(TreeNode*& k2)
{
	TreeNode* k1 = k2->left;

	 k2->left=k1->right;
	 k1->right = k2;

	 k2->high = k2->left->high > k2->right->high ? k2->left->high + 1 : k2->right->high + 1;
	 k1->high = k1->left->high > k1->right->high ? k1->left->high + 1 : k1->right->high + 1;

	 k2 = k1;
}
void Tree::doubleWithLeftChild(TreeNode*& k)
{
	rotateWithRightChild(k->left);
	rotateWithLeftChild(k);
}

void Tree::rotateWithRightChild(TreeNode*& k)
{
	TreeNode* temp = k->right;

	k->right = temp->left;      //这一步并不是给第一次旋转准备的，第一次之后的旋转中，这个位置可能会有数值

	temp->left = k;


	k->high= k->left->high > k->right->high ? k->left->high + 1 : k->right->high + 1;
	temp->high = temp->left->high > temp->right->high ? temp->left->high + 1 : temp->right->high + 1;

	k = temp;
	
}

void Tree::doubleWithRightChild(TreeNode*& k)
{
	rotateWithLeftChild(k->right);
	rotateWithRightChild(k);
}



void disTree(TreeNode* tree)     //通过递归遍历
{
	if (tree == NULL) return;

	printf("%d\n",tree->value);
	disTree(tree->left);
	disTree(tree->right);
}

void disTree2(TreeNode* tree)	//层序遍历
{
	if (tree == NULL) return;

	std::queue<TreeNode*> que;

	que.push(tree);

	while (!que.empty())
	{
		auto temp = que.front();

		std::cout << temp->value << std::endl;
		
		if (temp->left  != nullptr) que.push(temp->left );
		if (temp->right != nullptr) que.push(temp->right);
		
		que.pop();
			
	}

}

