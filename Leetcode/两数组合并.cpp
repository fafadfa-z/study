#include<iostream>


#include<fstream>

#include<vector>
#include<string>

using namespace std;



struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 插入链表的第一种实现。


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;



        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{

    ListNode* index1 = l1;
    ListNode* index2;

    ListNode* head = l1;

    if (l1 == nullptr) return l2;

    while (l2 != nullptr)
    {
        index2 = l2;

        l2 = l2->next;

        while (l1 != nullptr && l1->val < index2->val)   //循环到插入位置
        {
            index1 = l1;
            l1 = l1->next;
        }

        if (l1 == nullptr)   index1->next = index2;    // 对应在结尾插入的情况。

        else if (l1 == head)                             // 在头部插入
        {
            index2->next = index1;
            head = index1 = l1 = index2;
        }
        else
        {
            index2->next = l1;
            index1->next = index2;
            index1 = index2;
        }
    }
    return head;
}

int main1322()
{
    ListNode a(5), b(2, &a), l1(1, &b);
    ListNode aa(4), bb(3, &aa), l2(1, &bb);

    auto aaa = mergeTwoLists(&a, &l2);

    return 1;
}

