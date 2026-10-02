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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;
        ListNode* remove = head;
        ListNode* end = head;

        for (int i = 0; i < n; i++) end = end->next;

        if (!end) return head->next;

        while (end->next) {
            remove = remove->next;
            end = end->next;
        }

        remove->next = remove->next->next;

        return head;
    }
};
