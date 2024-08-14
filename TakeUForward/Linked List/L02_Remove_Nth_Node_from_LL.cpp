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
        ListNode *start = new ListNode();
        start->next = head;

        ListNode *p1 = start, *p2 = start;

        for(int i=0; i<n; i++) {
            p1 = p1->next;
        }

        while(p1->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        p2->next = p2->next->next;
        return start->next;
    }
};