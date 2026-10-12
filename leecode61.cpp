/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *r = head;
        if (r == nullptr) return head;
        int count_ = 1;
        while (r->next != nullptr)
        {
            r = r->next;
            count_ ++;
        }
        r->next = head;
        for (int i = 0;i < count_-(k%count_); i++)
        {
            head = head->next;
            r = r->next;
        }
        r->next = nullptr;
        return head;
    }
};