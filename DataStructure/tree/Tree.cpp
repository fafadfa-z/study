#include<stdlib.h>
#include<stdio.h>

#include<iostream>
#include<queue>   // �����Լ�ʵ�����ȶ��У������Դ��Ĵպϰ�

#include"tree.h"


void Tree::treeBuild(const vector<int>&nums)
{
	for (auto i : nums)
	{






	}
}

void Tree::insert(const int x, TreeNode*& t)
{
	if (t == nullptr) t = new TreeNode(x);    // ����ߵ�ͷ�ˣ����¿�һƬ�ռ䣬�������뵽��

	else if (x < t->value)    // ���������ϲ�
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

	t->high = height(t->left)> height(t->right)? height(t->left)+1: height(t->right)+1;// ������һ��Ҫ����ת֮���ټ���

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

	k->right = temp->left;      //��һ�������Ǹ���һ����ת׼���ģ���һ��֮�����ת�У����λ�ÿ��ܻ�����ֵ

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



void disTree(TreeNode* tree)     //ͨ���ݹ����
{
	if (tree == NULL) return;

	printf("%d\n",tree->value);
	disTree(tree->left);
	disTree(tree->right);
}

void disTree2(TreeNode* tree)	//�������
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

