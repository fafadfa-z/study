#pragma once

#include<iostream>

using namespace std;



// 1. 若两个模板的名称相同怎么办
// 2. 模板类的声明问题
// 3. 




class simNode
{
public:
	simNode(int Value,simNode* Next=nullptr)
		:value(Value), next(Next)
	{}
	simNode& operator=(const simNode& another);

	simNode* next;
	int value;
};


class Simple
{
public:
	Simple(int num=0);
	Simple(initializer_list<int>);

	~Simple();

	void addBegin(int num);  // 在链表首部添加元素

	void addEnd(int num);	 // 在链表尾部添加元素

	void display();			 // 顺序打印所有链表元素



private:

	void display(simNode*);

	simNode* retEnd(simNode*);

	void delNode(simNode*);

	simNode*  head;
};

