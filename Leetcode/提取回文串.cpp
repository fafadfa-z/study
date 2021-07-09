#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        maxSize = 0;
        index1 = 0;
        index2 = 0;

        if (s.size() == 1) return s;

        for (int i = 1; i < s.size(); i++)
            find(s, i);

        if (maxSize < 2)
            if (s[0] == s[1])
            {
                index1 = 0;
                index2 = 1;
            }
        string answer;
        for (int i = index1; i <= index2; ++i)
            answer += s[i];

        return  answer;
    }

    void find(string s, int i)
    {
        int k = 0;
        int j = 1;
        int curSize = 0;

        if (i == s.size() - 1)
        {
            if (s[i] == s[i - 1])
            {
                curSize = curSize < 2 ? 2 : curSize;
                j = 2;
                k = -1;
            }
            curSize = curSize == 0 ? 1 : curSize;
            fun(curSize, i, j, k);
            return;
        }

        else if (s[i] == s[i + 1])
        {
            curSize+=2;
            k = 1;
            for (; i - j >= 0 && i + j + 1 < s.size(); j++)
            {
                if (s[i - j] != s[i + j + 1]) break;
                curSize += 2;
            }
            fun(curSize, i, j, k);
        }

        curSize = 1;
        k = 0;
        j = 1;
        for (; i - j >= 0 && i + j < s.size(); j++)
        {

            if (s[i - j] != s[i + j]) break;
            curSize += 2;
        }
        fun(curSize, i, j, k);

    }
    void fun(int curSize, int i, int j, int k)
    {
        if (curSize > maxSize)
        {
            maxSize = curSize;
            index1 = i - j + 1;
            index2 = i + j + k - 1;
        }
    }
    int index1;
    int index2;
    int maxSize;
};


int main123()
{
    string st("ccc");

    Solution s;

    std::cout<<s.longestPalindrome(st);



    return 0;
}

