#pragma once


typedef struct TreeNode treeNode;


 struct TreeNode   // typedef �����ڽṹ��ɱ����ˡ���������
{
	treeNode* left;
	treeNode* right;

	int value;

};

treeNode* treeBuild(int[][3],const int);


void disTree(treeNode* tree);

void disTree2(treeNode* tree);