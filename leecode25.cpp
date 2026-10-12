#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ==================== 你的代码开始（原样未动） ====================
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) return head;
        ListNode *h = new ListNode(-2,head);
        ListNode *p = h->next, *pre = h, *r = p, *s = p->next;
        bool is_a_group = true;
        while (true)
        {
            for (int i = 0;i < k;i ++)
            {
                if (r == nullptr) {
                    return h->next;
                }
                r = r->next;
            }
            while (s != r)
            {
                p->next = s->next;
                s->next = pre->next;
                pre->next = s;
                s = p->next;
            }
            pre = p;
            p = p->next;
            if (p == nullptr)
            {
                return h->next;
            }
            
            s = p->next;
        }
    }
};
// ==================== 你的代码结束 ====================

// 辅助函数：从 vector 创建链表
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val;
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    // 构建测试用例
    vector<int> v1 = {1,2};
    vector<int> v2 = {5};
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);
    int k = 2;

    cout << "l1: ";
    printList(l1);
    cout << "l2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.reverseKGroup(l1,k);

    cout << "result: ";
    printList(result);
    system("pause");

    // 注意：你的代码会修改原链表，所以 l1 和 result 指向同一链表。
    // 这里不再重复打印 l1。

    return 0;
}