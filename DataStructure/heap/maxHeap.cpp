#include"maxHeap.h"





Heap::Heap(int Size)
	:capacity(Size),size(0)
{
	elements.assign(Size+1,-1); 

	elements[0] = maxData;   // ���Ҳ����ֵ�����е�Ԫ�ض���ʱ��������д���㷨����ô�㻹Ҫ������0��ǰ��ȥ�Ƚ�
							 // ��ʱ���Ǿ�ͨ��������޴��ֵ��Ƚϣ����䵲ס�����򽫳���Խ��
}

void Heap::insert(int val)
{
	if (full()) return;

	int i = ++size;

	for (; elements[i - 2] < val; i /= 2)    // ���ѵ������㷨
		elements[i] = elements[i / 2];		 // Ҫ��С�ڲ���ľ�����Ųһ�£�
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

