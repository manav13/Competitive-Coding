#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode *cur = head;
    
    while(cur!=NULL && cur->next!=NULL) {
        if(cur->val == (cur->next)->val) {
            cur->next = (cur->next)->next;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    return 0;
}