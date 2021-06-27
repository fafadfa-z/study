#ifndef _CIRCLE_H
#define	_CIRCLE_H	

#include<iostream>


using std::cout;
using std::endl;
using std::initializer_list;


class Circle;   //��������

class CircleNode
{
public:
	CircleNode(int Value=0, CircleNode* Forward= nullptr, CircleNode* Backward= nullptr)
		:value(Value), forward(Forward), backward(Backward) {}
	
	~CircleNode()=default;
	
	friend class Circle;      // 1. 

private:
	
	CircleNode* forward;
	CircleNode* backward;
	int value;

};



class Circle
{
public:
	Circle(initializer_list<int> );   // ��ʼ��

	void add(int num);				  // ��ӽڵ�

	~Circle();


private:

	CircleNode head;   // ����head֧���޲ι�����������Զ�����
					   
};



#endif
