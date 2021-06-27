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

   //如果这个名字跟声明的不同怎么办
Simple::Simple(initializer_list<int> list)

{
	if (list.size() == 0) throw;   // 检测参数列表是否为空

	auto temp = new simNode(*list.begin());    // 模板这里什么时候需要写 <> 

	head = temp;     //保留头指针 

	auto i = list.begin();
	for (++i;i!=list.end();++i)   //尾后迭代器，可以访问最后一个
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
	display(head);    //可以在函数内部调用它的重载
	cout << "\n";
}


void Simple::display(simNode* head)
{

	cout << head->value <<"    ";

	if (head->next != nullptr)	display(head->next);
	


}
