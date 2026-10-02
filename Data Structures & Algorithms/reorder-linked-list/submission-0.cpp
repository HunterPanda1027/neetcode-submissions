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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // 1. Find midpoint (slow ends at the end of the first half)
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Sever the list into two halves
        ListNode* curr = slow->next;
        slow->next = nullptr;

        // 2. Reverse the second half in-place
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }

        // 3. Zipper merge the two halves
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while (p2) {
            ListNode* p1_next = p1->next;
            ListNode* p2_next = p2->next;

            p1->next = p2;
            p2->next = p1_next;

            p1 = p1_next;
            p2 = p2_next;
        }
    }
};








