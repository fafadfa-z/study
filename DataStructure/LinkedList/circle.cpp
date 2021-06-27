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
	while (tem!=head.forward)   //�������Ҫ��ͼ����һ��
	{
		tem = tem->forward;
		delete tem->backward;
	} 
}

void Circle::add(int num)
{
	CircleNode* newNode = new CircleNode(num,head.forward, head.forward->backward);  //��ǰ��ڵ�ͺ���ڵ�ֱ�ָ��

	newNode->forward->backward = newNode;   //��ԭ���Ľڵ�ָ���¼ӵĽڵ�

	newNode->backward->forward = newNode;
}


