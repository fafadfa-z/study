#ifndef _GRAPH_H
#define _GRAPH_H

#include<vector>


using std::vector;


class Graph       // ͼ
{
public:
	Graph(int NodeNum)
		:nodeNum(NodeNum) {}



	virtual ~Graph() = 0;

	virtual void creat() = 0;        // ͨ������ڵ���Ϣ�ͽڵ����ݴ���ͼ

	virtual void travel()const = 0;       // ����ͼ����ʾ����

private:

	int* nodeMassage;   // �ڵ�������Ϣ	
	int* nodeVal;		   // �ڵ�������Ϣ

	int nodeNum;
};


class UndirGraph :public Graph        //ģ��Ԫ�̳�
{
public:

	//using Graph<T>::Graph();    // ��һ�¼̳й��캯��

	~UndirGraph() override;

	void creat(int**, int**) override;

	void travel()const override;


};







#endif