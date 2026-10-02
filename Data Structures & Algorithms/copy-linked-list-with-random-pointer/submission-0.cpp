/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        Node* current = head;
        cloneMap[nullptr] = nullptr;

        while (current) {
            Node* clone = new Node(current->val);
            cloneMap[current] = clone;
            current = current->next;
        }

        current = head;

        while (current) {
            cloneMap[current]->next = cloneMap[current->next];
            cloneMap[current]->random = cloneMap[current->random];
            current = current->next;
        }
        return cloneMap[head];
    }
};
