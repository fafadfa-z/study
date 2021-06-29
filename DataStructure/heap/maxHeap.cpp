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



int Heap::deleteHeap(int)     //�Ӷ����³�һ��Ԫ��(��Ϊʱ�����ȼ����������³����ڵ�)
{
	if (full()) return;

	int max = elements[1];

	int temp = elements[size--];
	
	int parent;
	int child = 0;

	for (parent = 1; parent * 2 <= size; parent = child)			 // �˶���ʾ���ڵ������ӽڵ㣬�ж����Ƿ��ڷ�Χ��
	{																 // ����һ��ÿ���½�һ��
		child = parent * 2;
		if (child != size && elements[child] < elements[child + 1])  // ����ҽڵ������ڵ㣬������ӽڵ��ָ��ָ���ҽڵ㡣
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
