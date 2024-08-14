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
        // External Space
        
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode *head = new ListNode();
        ListNode *cur = head;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                ListNode *temp = new ListNode(list1->val);
                cur->next = temp;
                cur = cur->next;

                list1 = list1->next;
            }
            else {
                ListNode *temp = new ListNode(list2->val);
                cur->next = temp;
                cur = cur->next;

                list2 = list2->next;
            }
        }
        
        if(list1 != nullptr) {
            cur->next = list1;
        }

        if(list2 != nullptr) {
            cur->next = list2;
        }

        return head->next;
    }
};