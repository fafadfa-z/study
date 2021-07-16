#include<iostream>
#include<vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#if 0

class MHeap {
public:
    MHeap(uint64_t k) {
        _heap.reserve(k);
    }

    void insertx(ListNode* nodep) {
        _heap.emplace_back(nodep);
        uint64_t child = _heap.size() - 1;
        while (child > 0) {
            uint64_t pa = (child - 1) / 2;
            child = pa * 2 + 1;
            if (child + 1 < _heap.size())
                child = _heap[child]->val <= _heap[child + 1]->val ? child : child + 1;
            if (_heap[child]->val < _heap[pa]->val)
                swap(_heap[child], _heap[pa]);
            else break;
            child = pa;
        }
    }

    void pop() {
        swap(_heap[0], _heap[_heap.size() - 1]);
        _heap.pop_back();
        uint64_t pa = 0, child = 1;
        while (pa * 2 + 1 < _heap.size()) {
            child = pa * 2 + 1;
            if (child + 1 < _heap.size())
                child = _heap[child]->val <= _heap[child + 1]->val ? child : child + 1;
            if (_heap[child]->val < _heap[pa]->val)
                swap(_heap[child], _heap[pa]);
            else break;
            pa = child;
        }
    }

    ListNode* top() {
        return _heap[0];
    }

    bool empty() {
        return _heap.empty();
    }
private:
    vector<ListNode*> _heap;
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;

        MHeap heap(lists.size());

        for (auto& it : lists) 
        {
            if (it)
                heap.insertx(it);
        }

        ListNode* dummy = new ListNode(0), * p = dummy;

        while (!heap.empty()) 
        {
            ListNode* temp = heap.top();
            heap.pop();
            p->next = temp;
            if (temp->next)
                heap.insertx(temp->next);
            p = p->next;
        }

        return dummy->next;
    }
};

#endif

int main()
{
   

    /*s.mergeKLists();*/

    return 0;
}


