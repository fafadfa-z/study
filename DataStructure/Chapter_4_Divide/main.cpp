#include<iostream>

#include"divide.h"









int main()
{
	vector<int> a = {4,-3,5,-2,-1,2,6,-2};

	int b=maxSumRec(a,0,7);

	std::cout << b<<std::endl;





	return 1;
}


