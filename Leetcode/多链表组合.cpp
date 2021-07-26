#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    bool checkValidString(string s)
    {
        int countR = 0;
        int countS = 0;

        for (auto ch : s)
        {
            if (ch == '(') countR++;
            else if (ch == '*') countS++;
            else
            {
                if (countR)
                    countR--;
                else if (countS)
                    countS--;
                else return false;
            }
        }

        if (countR <= countS || countR == 0)
            return true;
        return false;
    }


};

int main()
{
    string str("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())");

    Solution s;
    s.checkValidString(str);
    

    return 0;
}


