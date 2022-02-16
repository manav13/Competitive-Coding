#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairsRecursion(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
        
    // reverse 2 nodes
    ListNode *cur = head, *nex = cur->next, *prev = nullptr;
    
    cur->next = swapPairsRecursion(head->next->next);
    nex->next = cur;
    return nex;
}

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* prev = head, *cur = head->next;
    head = head->next;
    if(head->next == nullptr) {
        cur->next = prev;
        prev->next = nullptr;
        return head;
    }
    while(prev->next != nullptr && cur->next != nullptr) {
        if(prev->next != head) {
            prev->next = cur->next;
            prev = prev->next;
        }
        else {
            ListNode *temp = new ListNode(0);
            temp->next = prev;
            prev->next = cur->next;
            cur->next = temp->next;
            
            cur = prev->next;
            continue;
        }
        cur->next = prev->next;
        prev->next = cur;
        
        // move pointers
        prev = cur;
        cur = cur->next;
    }
    return head;
}

int main() {
    return 0;
}