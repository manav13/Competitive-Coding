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
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) return head;
        
        ListNode* slow = head, *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next!=nullptr) slow = slow->next;
        return slow;
    }
};

int main() {
    return 0;
}