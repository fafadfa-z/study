#include"circle.h"


Circle::Circle(initializer_list<int> list)
	:head(-1)
{
	CircleNode* h = &head;

	for (auto i : list)
	{
		h->forward = new CircleNode(i,nullptr,h);
		h = h->forward;
	}
	h->forward = head.forward;

	head.forward->backward = h;

}


Circle::~Circle()
{
	CircleNode* tem = head.forward;
	while (tem!=head.forward)   //这个还是要画图分析一下
	{
		tem = tem->forward;
		delete tem->backward;
	} 
}

void Circle::add(int num)
{
	CircleNode* newNode = new CircleNode(num,head.forward, head.forward->backward);  //将前向节点和后向节点分别指向

	newNode->forward->backward = newNode;   //将原来的节点指向新加的节点

	newNode->backward->forward = newNode;
}


