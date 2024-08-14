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

    ListNode* reverse(ListNode* cur, ListNode* end) {
        ListNode *prev = end, *next = nullptr;

        while(cur != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start = new ListNode();
        start->next = head;

        int count = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            count++;
            cur = cur->next;
        }
        
        ListNode *p1 = start, *p2 = start;
        count = count/k;
        for(int i=0; i<count; i++) {
            for(int j=0; j<k; j++) {
                p2 = p2->next;
            }
            p1->next = reverse(p1->next, p2->next);
            for(int j=0; j<k; j++) {
                p1 = p1->next;
            }
            p2 = p1;
        }
        return start->next;
    }
};