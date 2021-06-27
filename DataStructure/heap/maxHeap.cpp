#include"maxHeap.h"





Heap::Heap(int Size)
	:capacity(Size),size(0)
{
	elements.assign(Size+1,-1); 

	elements[0] = maxData;   // 在我插入的值比所有的元素都大时，按我们写的算法，我么你还要继续向0的前面去比较
							 // 这时我们就通过跟这个巨大的值相比较，将其挡住，否则将出现越界
}

void Heap::insert(int val)
{
	if (full()) return;

	int i = ++size;

	for (; elements[i - 2] < val; i /= 2)    // 最大堆的排序算法
		elements[i] = elements[i / 2];		 // 要是小于插入的就向下挪一下，
	elements[i] = val;						 // 


}
void Heap::deleteHeap(int)
{
	if (full()) return;

	int max = elements[1];

	int temp = elements[size--];
	
	int parent, child;

	for (parent = 1; parent * 2 <= size; parent = child)
	{
		
	}



}

