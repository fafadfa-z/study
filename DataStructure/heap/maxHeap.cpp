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



int Heap::deleteHeap(int)     //从堆中吐出一个元素(因为时按优先级，所以是吐出根节点)
{
	if (full()) return;

	int max = elements[1];

	int temp = elements[size--];
	
	int parent;
	int child = 0;

	for (parent = 1; parent * 2 <= size; parent = child)			 // 乘二表示父节点的左边子节点，判断期是否在范围内
	{																 // 堆中一般每次下降一层
		child = parent * 2;
		if (child != size && elements[child] < elements[child + 1])  // 如果右节点大于左节点，则令儿子节点的指针指向右节点。
			child++;
		if (temp >= elements[child]) break;								
		else
			elements[parent] = elements[child];
	}
	elements[parent] = temp;

	return max;

}

void Heap::init(vector<int>list)
{
	for (auto i : list)
		elements.push_back(i);

	int index = list.size();


}
