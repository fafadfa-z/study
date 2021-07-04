#include"fastSort.h"


// 快速排序
int partition(int nums[], int index1, int index2)
{
	int x = nums[index2];   // 一般找最后一个作为标准的比较点，将所有小于它的放到它前面去。

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



//计数排序。
const int num = 100; // 假设输入的每一个元素不能超过 num
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
