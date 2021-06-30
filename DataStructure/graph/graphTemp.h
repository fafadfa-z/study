#ifndef _GRAPHTHMP_H
#define _GRAPHTEMP_H

#include<vector>

using std::vector;

#if 0

template<typename T>
class Graph       // 图
{
public:
	Graph(int NodeNum)
		:nodeNum(NodeNum){}



	virtual ~Graph()=0;

	virtual void creat(T**, T**)=0;        // 通过传入节点信息和节点数据创建图

	virtual void travel()const = 0;       // 遍历图并显示出来

private:

	T*  nodeMassage;   // 节点连接信息	
	T*  nodeVal;		   // 节点数据信息

	int nodeNum;
};

template<typename T1,typename T2>
class UndirGraph :public Graph<	T1>        //模板元继承
{
public:

	//using Graph<T>::Graph();    // 试一下继承构造函数

	~UndirGraph() = override;

	void creat(T1**, T1**) override;

	void travel()override;
};
#endif






#endif // !_GRAPH_H
