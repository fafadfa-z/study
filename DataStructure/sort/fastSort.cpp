#include"fastSort.h"


// ��������
int partition(int nums[], int index1, int index2)
{
	int x = nums[index2];   // һ�������һ����Ϊ��׼�ıȽϵ㣬������С�����ķŵ���ǰ��ȥ��

	int i = index1 - 1;

	for (int j = index1; j < index2 - 1; ++j)
	{
		if (nums[j] < x)
		{
			i++;
			nums[i] = nums[i] ^ nums[j];
			nums[j] = nums[i] ^ nums[j];
			nums[i] = nums[i] ^ nums[j];
		}
	}
	nums[i + 1] = nums[i + 1] ^ nums[index2];
	nums[index2] = nums[i + 1] ^ nums[index2];
	nums[i + 1] = nums[i + 1] ^ nums[index2];
	
	return i + 1;
}

void fastSort(int nums[], int index1, int index2)
{
	if (index1 < index2)
	{
		int q = partition(nums, index1, index2);

		fastSort(nums, index1, q - 1);
		fastSort(nums, q+1,index2);
	}
}

/*-----------------------------------------------------------------*/



//��������
const int num = 100; // ���������ÿһ��Ԫ�ز��ܳ��� num
void jishuSort(vector<int>& input)
{
	array<int, num> temp = {0};

	vector<int> answer(num, 0);

	for (size_t i = 0; i < input.size(); ++i)
		temp[input[i]]++;
	
	for (size_t i = 0; i < num; ++i)
		temp[i] = temp[i] + temp[i - 1];

	for (size_t i = 0; i < input.size(); ++i)
	{
		answer[temp[input[i]]] = input[i];
		temp[input[i]]--;
	}


}
