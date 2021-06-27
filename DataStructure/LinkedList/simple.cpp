#include "simple.h"


simNode& simNode::operator=(const simNode& another)
{
	if (this != &another)
	{
		this->next = another.next;
	}

	return *this;

}
Simple::Simple(int num)
	:head(new simNode(num))
{
}

void Simple::delNode(simNode* head)
{
	if (head->next != nullptr)  delNode(head->next);

	delete head;

}

Simple::~Simple()
{
	delNode(head);
}

   //���������ָ������Ĳ�ͬ��ô��
Simple::Simple(initializer_list<int> list)

{
	if (list.size() == 0) throw;   // �������б��Ƿ�Ϊ��

	auto temp = new simNode(*list.begin());    // ģ������ʲôʱ����Ҫд <> 

	head = temp;     //����ͷָ�� 

	auto i = list.begin();
	for (++i;i!=list.end();++i)   //β������������Է������һ��
	{
		temp->next = new simNode(*i);
		temp = temp->next;
	}

}

void Simple::addBegin(int num)
{
	simNode *temp=new simNode(num);

	temp->next = head;

	head = temp;

}

void Simple::addEnd(int num)
{
	simNode* temp = retEnd(head);

	temp->next = new simNode(num);
}

simNode* Simple::retEnd(simNode*head)
{
	if (head->next != nullptr)	
		return retEnd(head->next);


	return head;
}

void Simple::display()
{
	display(head);    //�����ں����ڲ�������������
	cout << "\n";
}


void Simple::display(simNode* head)
{

	cout << head->value <<"    ";

	if (head->next != nullptr)	display(head->next);
	


}
