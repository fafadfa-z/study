#include<iostream>


#include<fstream>


#include<string>

using namespace std;


// 链表的加减法
// 指针的使用加强


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
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int temp = 0;
        int jinwei = 0;
        int first = 0;

        ListNode* answer = new ListNode(-1);
        ListNode* ans = answer;


        while (l1 != nullptr || l2 != nullptr || jinwei != 0)
        {
            if (l1 != nullptr)
            {
                jinwei += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                jinwei += l2->val;
                l2 = l2->next;
            }
            ans->next = new ListNode(jinwei % 10);
            jinwei /= 10;


            ans = ans->next;
        }

        return answer->next;
    }


};






int main1()
{
    ListNode* a(new ListNode(1)), * b(new ListNode(2, a)), * c(new ListNode(3, b));

    ListNode* aa(new ListNode(1)), * bb(new ListNode(2, a)), * cc(new ListNode(3, b));

    Solution::addTwoNumbers(c, cc);




    return 1;
}