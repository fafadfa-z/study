#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include<vector>


#if 0
class HeapNode
{
	HeapNode(int Val=0, HeapNode* Left=nullptr,HeapNode* Right=nullptr)
	:val(Val),left(Left),right(Right){}


	friend class Heap;
private:

	int val;
	
	HeapNode* left;
	HeapNode* right;
};

#endif


const int maxData = 60000;

class Heap
{
public:
	Heap(int Size);

	void insert(int);
	void deleteHeap(int);


private:

	inline bool full()
	{
		return size == capacity;
	}


	std::vector<int> elements;
	int size;		 // 当前最大值
	int capacity;    // 允许存放的最大值


};






#endif