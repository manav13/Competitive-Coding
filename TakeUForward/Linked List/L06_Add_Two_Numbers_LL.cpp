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
        ListNode *cur = new ListNode();
        ListNode *head = cur;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            ListNode *temp = new ListNode(sum);
            cur->next = temp;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr) {
            int sum = l1->val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            ListNode *temp = new ListNode(sum);
            cur->next = temp;
            cur = cur->next;
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            int sum = l2->val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            ListNode *temp = new ListNode(sum);
            cur->next = temp;
            cur = cur->next;
            l2 = l2->next;
        }

        if(carry == 1) {
            ListNode *temp = new ListNode(1);
            cur->next = temp;
            cur = cur->next;
        }

        return head->next;
    }
};