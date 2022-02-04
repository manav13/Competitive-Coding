#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return head;
    
    ListNode *p1 = nullptr, *p2 = head;
    while(n > 1 && p2->next!=nullptr) {
        p2 = p2->next;
        n--;
    }
    while(p2->next!=nullptr ) {
        if(p1==nullptr) {
            p1 = head;
        }
        else p1 = p1->next;
        p2 = p2->next;
    }
    
    if(p1==nullptr) head = head->next;
    else p1->next = (p1->next)->next;
    
    
    return head;
}

int main() {
    return 0;
}