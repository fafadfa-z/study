#ifndef _GRAPHTHMP_H
#define _GRAPHTEMP_H

#include<vector>

using std::vector;

#if 0

template<typename T>
class Graph       // ͼ
{
public:
	Graph(int NodeNum)
		:nodeNum(NodeNum){}



	virtual ~Graph()=0;

	virtual void creat(T**, T**)=0;        // ͨ������ڵ���Ϣ�ͽڵ����ݴ���ͼ

	virtual void travel()const = 0;       // ����ͼ����ʾ����

private:

	T*  nodeMassage;   // �ڵ�������Ϣ	
	T*  nodeVal;		   // �ڵ�������Ϣ

	int nodeNum;
};

template<typename T1,typename T2>
class UndirGraph :public Graph<	T1>        //ģ��Ԫ�̳�
{
public:

	//using Graph<T>::Graph();    // ��һ�¼̳й��캯��

	~UndirGraph() = override;

	void creat(T1**, T1**) override;

	void travel()override;
};
#endif






#endif // !_GRAPH_H
