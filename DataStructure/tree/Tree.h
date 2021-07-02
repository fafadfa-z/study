#pragma once

#include <climits>

#include<vector>
#include<array>
#include<queue>   // �����Լ�ʵ�����ȶ��У������Դ��Ĵպϰ�

using std::array;
using std::vector;

class TreeNode   // typedef �����ڽṹ��ɱ����ˡ���������
{
public:
	TreeNode(int Value = 0, TreeNode* Left=nullptr, TreeNode* Right=nullptr,size_t High=0)
		:value(Value), left(Left), right(Right),high(High) {}

	TreeNode* left;
	TreeNode* right;

	int value;
	int high;
};



class Tree
{

public:
	Tree() :treeRoot(INT_MAX) {}  //����һ���赲

	void treeBuild(const vector<int>&);
	
	inline int height(TreeNode* tree) const 
	{
		return tree == nullptr ? -1 : tree->high;
	}


	void insert(const int x,TreeNode* &t );   // ָ�������

	
	void rotateWithLeftChild(TreeNode*&);    // ����
	void doubleWithLeftChild(TreeNode*&);	 // ������

	void rotateWithRightChild(TreeNode*&);	 // ����
	void doubleWithRightChild(TreeNode*&);	 // ������



private:
	TreeNode treeRoot;   //����֮��Ľڵ�
};


