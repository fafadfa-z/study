#pragma once

#include <climits>

#include<vector>
#include<array>
#include<queue>   // 不想自己实现优先队列，先用自带的凑合吧

using std::array;
using std::vector;

class TreeNode   // typedef 作用于结构体可别忘了。。。。。
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
	Tree() :treeRoot(INT_MAX) {}  //设置一个阻挡

	void treeBuild(const vector<int>&);
	
	inline int height(TreeNode* tree) const 
	{
		return tree == nullptr ? -1 : tree->high;
	}


	void insert(const int x,TreeNode* &t );   // 指针的引用

	
	void rotateWithLeftChild(TreeNode*&);    // 左旋
	void doubleWithLeftChild(TreeNode*&);	 // 右左旋

	void rotateWithRightChild(TreeNode*&);	 // 右旋
	void doubleWithRightChild(TreeNode*&);	 // 左右旋



private:
	TreeNode treeRoot;   //树根之后的节点
};


