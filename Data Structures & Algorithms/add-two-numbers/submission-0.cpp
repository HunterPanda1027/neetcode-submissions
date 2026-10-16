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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // Stack dummy node avoids manual memory management
        ListNode* curr = &dummy;    // Pointer used to build the result chain
        int carry = 0;

        // Loop as long as there are digits to add or a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;      // Advance l1
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;      // Advance l2
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;          // Return head of the actual result
    }
};
