#pragma once

#include<iostream>

using namespace std;



// 1. ������ģ���������ͬ��ô��
// 2. ģ�������������
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

	void addBegin(int num);  // �������ײ����Ԫ��

	void addEnd(int num);	 // ������β�����Ԫ��

	void display();			 // ˳���ӡ��������Ԫ��



private:

	void display(simNode*);

	simNode* retEnd(simNode*);

	void delNode(simNode*);

	simNode*  head;
};

