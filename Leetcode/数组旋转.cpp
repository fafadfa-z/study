#include<iostream>


#include<fstream>

#include<vector>
#include<string>

using namespace std;

#if 0

void rotate(vector<int> nums, int k) 
{
    if (nums.size() == 0) return;
    k %= nums.size();
    help(nums, 0, nums.size() - 1);
    help(nums, 0, k - 1);
    help(nums, k, nums.size() - 1);


}
void help(vector<int>  arr, int l, int r) {
    if (l >= r) return;
    while (l < r) {
        int tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}

#endif


int main2()
{



	return 1;
}