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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val > list2->val) {
            return mergeTwoLists(list2, list1);
        }

        ListNode* curr = list1;
        ListNode* next1 = list1->next;
        ListNode* next2 = list2;

        while(next1 || next2) {
            if(next1 == nullptr) {
                curr->next = next2;
                break;
            } else if (next2 == nullptr) {
                curr->next = next1;
                break;
            } else if (next1->val <= next2->val) {
                curr->next = next1;
                curr = next1;
                next1 = next1->next;
            } else {
                curr->next = next2;
                curr = next2;
                next2 = next2->next;
            }
        }
        return list1;
    }
};
