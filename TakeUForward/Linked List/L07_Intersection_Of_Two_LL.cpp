/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // TC = O(M+N) SC = O(M)
        unordered_set<ListNode*> set;

        while(headA != nullptr) {
            set.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr) {
            if(set.find(headB) != set.end())
                return headB;

            headB = headB->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Reduced space complexity
        // TC = 2*O(M+N) SC = O(1)
        int l1 = 0, l2 = 0;
        ListNode *d1 = headA, *d2 = headB;

        // Find length of L1
        while(d1 != nullptr) {
            l1 += 1;
            d1 = d1->next;
        }

        // Find length of L2
        while(d2 != nullptr) {
            l2 += 1;
            d2 = d2->next;
        }

        // Cover the difference
        d1 = headA;
        d2 = headB;
        for(int i=0; i<abs(l1-l2); i++) {
            if(l1 > l2) {
                d1 = d1->next;
            }
            else {
                d2 = d2->next;
            }
        }

        while(d1 != nullptr && d2 != nullptr && d1 != d2) {
            d1 = d1->next;
            d2 = d2->next;
        }
        return d1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Easy coding practice
        // TC = 2*O(M+N) SC = O(1)
        ListNode *a = headA, *b = headB;

        while(a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        return a;
    }
};