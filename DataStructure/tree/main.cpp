#include<stdio.h>
#include"tree.h"


#if 0 

树的一些基本定义：

度 : 节点的度：	节点子树的个数
数的度：	最大的度数

斜二叉树：				只有一边的树
完美二叉树（满二叉树）	全是满的
完全二叉树				按序号，最后一点可以缺失


对于二叉树：			n0 = n2 + 1


三种递归的顺序：
先序	根、左、右		及第一次到达时就访问
中序	左、跟、右		第二次
后续	左、右、跟		第三次


顺序储存的节点序号特点，对于i节点：
父节点 为 1 / 2i
左孩子 为 2i
右孩子 为 2i + 1

#endif 



#include<stdlib.h>

void fun()
{

	int** num = (int**)malloc(sizeof(int*)*5);

	for (int i = 0; i < 5; ++i)
	{
		printf("woshi   %x  \n",(unsigned int)&num[i]);

	}
}


int main()
{

	//int a[8][3] = { {2,6,5}, {7,-1,4}, {1,0,3}, {6,-1,1},{8,-1,-1},{4,-1,-1},{3,7,-1},{5,-1,-1} };
	//treeNode* tree = treeBuild(a, 8);

	//disTree2(tree);

	//fun();



	return 1;
}

