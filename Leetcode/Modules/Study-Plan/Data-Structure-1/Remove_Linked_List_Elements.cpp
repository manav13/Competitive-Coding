#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return head;
    while(head!=NULL && head->val == val) head = head->next;
    if(head == NULL) return head;
    ListNode* cur = head->next, *prev = head;
    
    while(cur!=NULL) {
        if(cur->val == val) {
            prev->next = cur->next;
        }
        else prev = cur;
        
        cur = cur->next;
        
    }
    return head;
}

int main() {
    return 0;
}