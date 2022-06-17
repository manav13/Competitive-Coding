#include<bits/stdc++.h>
using namespace std;

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
        ListNode* head = new ListNode();
        ListNode *p1 = list1, *p2 = list2, *p3 = head;
        while(p1!=nullptr && p2!=nullptr) {
            if(p1->val < p2->val) {
                ListNode* temp = new ListNode(p1->val);
                p3->next = temp;
                p1 = p1->next;
                p3 = p3->next;
            }
            else {
                ListNode* temp = new ListNode(p2->val);
                p3->next = temp;
                p2 = p2->next;
                p3 = p3->next;
            }
        }
        if(p1 == nullptr) {
            while(p2 != nullptr) {
                // new node
                ListNode* temp = new ListNode(p2->val);
                p3->next = temp;
                p2 = p2->next;
                p3 = p3->next;
            }
        }
        else if (p2 == nullptr) {
            while(p1 != nullptr) {
                ListNode* temp = new ListNode(p1->val);
                p3->next = temp;
                p1 = p1->next;
                p3 = p3->next;
            }
        }
        return head->next;
    }
};

int main() {
    return 0;
}