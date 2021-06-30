#ifndef _GRAPH_H
#define _GRAPH_H

#include<vector>


using std::vector;


class Graph       // 图
{
public:
	Graph(int NodeNum)
		:nodeNum(NodeNum) {}



	virtual ~Graph() = 0;

	virtual void creat() = 0;        // 通过传入节点信息和节点数据创建图

	virtual void travel()const = 0;       // 遍历图并显示出来

private:

	int* nodeMassage;   // 节点连接信息	
	int* nodeVal;		   // 节点数据信息

	int nodeNum;
};


class UndirGraph :public Graph        //模板元继承
{
public:

	//using Graph<T>::Graph();    // 试一下继承构造函数

	~UndirGraph() override;

	void creat(int**, int**) override;

	void travel()const override;


};







#endif