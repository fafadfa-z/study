struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ��Ҫѧϰ���ݣ�
// 1. ���� new��ʱ�򴫲�������
// 2. ����ض�����

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        int count = 0;
        TreeNode* tree = new TreeNode(0);

        if (head == nullptr)  return nullptr;

        ListNode* tempNode = head;

        while (tempNode != nullptr)    //�ȵó�һ���ж��ٸ��ڵ㡣
        {
            count++;
            tempNode = tempNode->next;
        }

        digui(tree, head, count);

        return tree;
    }

    void digui(TreeNode* tree, ListNode* head, int num)
    {
        ListNode* lastPart = head;  //�����������

        if (head == nullptr)
        {

            return;
        }
        if (head->next == nullptr)
        {
            tree->val = head->val;
            return;
        }

        for (int i = 0; i < num / 2 - 1; i++)
            lastPart = lastPart->next;

        ListNode* temp = lastPart;

        lastPart = lastPart->next;
        temp->next = nullptr;

        tree->val = lastPart->val;

        if (head != nullptr)
        {
            tree->left = new TreeNode(-1);
            digui(tree->left, head, num / 2); // ǰ���
        }
        if (lastPart->next != nullptr)
        {
            tree->right = new TreeNode(-1);
            digui(tree->right, lastPart->next, num - num / 2 - 1);
        }
    }
};
int main()
{
    ListNode  a(1), b(2, &a), c(3, &b), d(4, &c), e(5, &d);

    Solution s;

    TreeNode* temp = s.sortedListToBST(&e);

    temp = nullptr;

    return 1;
}
