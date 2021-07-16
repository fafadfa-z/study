

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry_bit = 0;

        ListNode* ans = new ListNode(0), * head = ans;


        while (l1 != nullptr || l2 != nullptr)
        {
            int a = 0, b = 0;

            if (l1 != nullptr)
            {
                a = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                b = l2->val;
                l2 = l2->next;
            }

            ans->next = new ListNode((a + b + carry_bit) % 10);
            carry_bit = (a + b) / 10;
            ans = ans->next;

        }
        return head;
    }
};


int main()
{
    ListNode a(3), b(4, &a), c(2, &b);
    ListNode aa(4), bb(6, &aa), cc(5, &bb);

    Solution s;

    s.addTwoNumbers(&c,&cc);





    return 0;
}