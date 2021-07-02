#include"Divide.h"






// ʹ�õݹ����ʽ�����������͵����⡣
int maxSumRec(const vector<int>&a,int left,int right)   // ʱ�临�Ӷȣ� ��nlogn��
{
	if (left == right) return a[left] > 0 ? a[left] : 0;    // ������˵ ���︳����ֵΪ�㶼�ǿ��Ե�

	int center = (left + right) / 2;

	int maxLeftSum  = maxSumRec(a,left,center);
	int maxRightSum = maxSumRec(a, center+1, right);

	int leftSum = 0, leftSumMax = 0;

	for (int i = center; i >=left; --i)    //��ط������Ƿ���ѭ����Ѱ�����ŷֽ������������
	{
		leftSum += a[i];
		if (leftSum > leftSumMax) leftSumMax = leftSum;
	}
	int rightSum = 0, rightSumMax = 0;

	for (int i = center+1; i <= right; ++i)
	{
		rightSum += a[i];
		if (rightSum > rightSumMax) rightSumMax = rightSum;
	}
	
	if (maxLeftSum < rightSumMax + leftSumMax) maxLeftSum = rightSumMax + leftSumMax;
	
	if (maxLeftSum < maxRightSum) maxLeftSum = maxRightSum;

	return maxLeftSum;
}

// �����������͵�����, ʹ�������㷨�� ����õġ�     
int maxSumRec2(const vector<int>& a, int left, int right)   // ʱ�临�Ӷȣ� ��n��
{
	int maxSum = 0, thisSum = 0;

	for (auto i = 0; i < a.size(); ++i)
	{
		thisSum += a[i];

		if (thisSum > maxSum) maxSum = thisSum;
		else if (thisSum < 0) thisSum = 0;
	}
	return maxSum;
}

// ���������Լ����ŷ������㷨
long gcd(long m,long n)
{
	if (m < n)
	{
		m = m ^ n;
		n = m ^ n;
		m = m ^ n;
	}

	while (n != 0)
	{
		long rem = m % n;
		m = n;
		n = rem;
	}

	return m;


}

