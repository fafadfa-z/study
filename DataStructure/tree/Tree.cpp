#include<stdlib.h>
#include<stdio.h>

#include<iostream>
#include<queue>   // 不想自己实现优先队列，先用自带的凑合吧

#include"tree.h"



treeNode* treeBuild(int treeMessage[][3],const int num)
{	
	int i = 0;

	int* record = (int*)malloc(sizeof(int)*num);

	if (record == NULL) return NULL;

	for (i = 0; i < num; ++i) record[i] = 0;


	treeNode** tree = (treeNode**)malloc(sizeof(treeNode*)*num);   //二重指针的初始话一定要熟悉

	if (tree == NULL) return NULL;

	for (i = 0; i < num; ++i)
	{
		tree[i] = (treeNode*)malloc(sizeof(treeNode));
		if (tree[i] == NULL) return NULL;
	}
		
	for (i = 0; i < num; ++i)
	{
		tree[i]->value = treeMessage[i][0];

		tree[i]->left  = treeMessage[i][1] == -1 ? NULL : (treeNode*)tree[treeMessage[i][1]];
		tree[i]->right = treeMessage[i][2] == -1 ? NULL : (treeNode*)tree[treeMessage[i][2]];

	
		//treeMessage[i][1] == -1 ? tree[i]->left = NULL: (tree[i]->left = treeMessage[i][1]);   //  赋值运算符的优先级是高于三目运算符的，所以在最后要加括号

		treeMessage[i][1] == -1 ? NULL : (record[treeMessage[i][1]])++;
		treeMessage[i][2] == -1 ? NULL : (record[treeMessage[i][2]])++;

		//printf("%d   %d\n", treeMessage[i][1],treeMessage[i][2]);

	}

	for (i = 0; i < num; ++i)	
		if (!record[i])
		{
			free(record);      //若malloc 申请的内存被越界了，free时会报错

			return tree[i];
		}
	return NULL;
}

void disTree(treeNode* tree)     //通过递归遍历
{
	if (tree == NULL) return;

	printf("%d\n",tree->value);
	disTree(tree->left);
	disTree(tree->right);
}

void disTree2(treeNode* tree)	//层序遍历
{
	if (tree == NULL) return;

	std::queue<treeNode*> que;  

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

