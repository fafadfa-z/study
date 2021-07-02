#include"Divide.h"






// 使用递归的形式求最大子数组和的问题。
int maxSumRec(const vector<int>&a,int left,int right)   // 时间复杂度： （nlogn）
{
	if (left == right) return a[left] > 0 ? a[left] : 0;    // 按理来说 这里赋不赋值为零都是可以的

	int center = (left + right) / 2;

	int maxLeftSum  = maxSumRec(a,left,center);
	int maxRightSum = maxSumRec(a, center+1, right);

	int leftSum = 0, leftSumMax = 0;

	for (int i = center; i >=left; --i)    //这地方必须是反向循环，寻找沿着分界面最大的数组和
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

// 求最大子数组和的问题, 使用联机算法。 是最好的。     
int maxSumRec2(const vector<int>& a, int left, int right)   // 时间复杂度： （n）
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

// 用来求最大公约数的欧几里得算法
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

