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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;
        
        ListNode *prev = nullptr, *next = nullptr, *cur = head;
        while(cur!=nullptr) {
            next = cur->next;
            cur->next = prev;
            prev =cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    return 0;
}