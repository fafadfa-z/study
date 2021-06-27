#include<stdlib.h>
#include<stdio.h>

#include<iostream>
#include<queue>   // �����Լ�ʵ�����ȶ��У������Դ��Ĵպϰ�

#include"tree.h"



treeNode* treeBuild(int treeMessage[][3],const int num)
{	
	int i = 0;

	int* record = (int*)malloc(sizeof(int)*num);

	if (record == NULL) return NULL;

	for (i = 0; i < num; ++i) record[i] = 0;


	treeNode** tree = (treeNode**)malloc(sizeof(treeNode*)*num);   //����ָ��ĳ�ʼ��һ��Ҫ��Ϥ

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

	
		//treeMessage[i][1] == -1 ? tree[i]->left = NULL: (tree[i]->left = treeMessage[i][1]);   //  ��ֵ����������ȼ��Ǹ�����Ŀ������ģ����������Ҫ������

		treeMessage[i][1] == -1 ? NULL : (record[treeMessage[i][1]])++;
		treeMessage[i][2] == -1 ? NULL : (record[treeMessage[i][2]])++;

		//printf("%d   %d\n", treeMessage[i][1],treeMessage[i][2]);

	}

	for (i = 0; i < num; ++i)	
		if (!record[i])
		{
			free(record);      //��malloc ������ڴ汻Խ���ˣ�freeʱ�ᱨ��

			return tree[i];
		}
	return NULL;
}

void disTree(treeNode* tree)     //ͨ���ݹ����
{
	if (tree == NULL) return;

	printf("%d\n",tree->value);
	disTree(tree->left);
	disTree(tree->right);
}

void disTree2(treeNode* tree)	//�������
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

