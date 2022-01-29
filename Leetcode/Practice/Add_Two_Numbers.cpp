#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *head = new ListNode(0);
    ListNode *ans = head;
    
    // Append the  nodes     
    while(l1!=NULL || l2!=NULL) {
        int sum = carry;
        
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;
        
        carry = (int) (sum/10);
        ListNode *newNode = new ListNode(sum%10);
        ans->next = newNode;
        
        ans = ans->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry!=0) {
        ListNode *newNode = new ListNode(carry);
        ans->next = newNode;
    }
    return head->next;
}

int main() {
    return 0;
}