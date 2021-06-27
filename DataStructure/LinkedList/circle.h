#ifndef _CIRCLE_H
#define	_CIRCLE_H	

#include<iostream>


using std::cout;
using std::endl;
using std::initializer_list;


class Circle;   //环形链表

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
	Circle(initializer_list<int> );   // 初始化

	void add(int num);				  // 添加节点

	~Circle();


private:

	CircleNode head;   // 若是head支持无参构造器，则会自动调用
					   
};



#endif
