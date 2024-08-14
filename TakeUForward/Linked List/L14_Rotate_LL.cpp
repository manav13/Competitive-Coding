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
        if(head == nullptr)
            return head;
        
        int len = 0;
        ListNode *node = head;
        ListNode *last;
        while(node != nullptr) {
            len += 1;
            if(node->next == nullptr)
                last = node;

            node = node->next;
        }

        k = k%len;

        // Make a cycle;
        last->next = head;

        // Move head len-k times
        ListNode *newHead = head;
        for(int i=0; i<len-k; i++) {
            newHead = newHead->next;
        }

        // Break cycle before newHead
        node = head;
        while(node->next != newHead) {
            node = node->next;
        }

        node->next = nullptr;

        return newHead;
    }
};