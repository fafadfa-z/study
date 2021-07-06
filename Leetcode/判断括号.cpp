#include<string>

using namespace std;


class Solution {
public:
    bool isValid(string s)
    {
        int index = 0;
        while (index < s.size())
        {
            if (digui(s, index) == false) return false;
        }

        return true;

    }

    bool digui(const string s, int& index)
    {
        if (s[index] == '(' || s[index] == '[' || s[index] == '{')
        {
            char temp = s[index];

            if (index < s.size() - 1) index++;

            else return false;             //到最后了没找到第二个括号


            if (search(s[index]) == search(temp) + 3)    //找到对应的括号
            {
                return true;
            }
            else if (digui(s, index) == false)   return false;

        }
        return false;
    }

    int  search(char ch)
    {

        for (unsigned char i = 0; i < 6; ++i)
            if (str[i] == ch) return i;
        return -1;
    }

    string str = "([{)]}";
};




int main()
{
    string st("()");

    Solution s;

    s.isValid(st);



    return 0;
}

