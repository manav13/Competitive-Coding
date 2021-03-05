#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute force Solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA, *curB = headB;
    while(curA) {
        curB = headB;
        while(curB) {
            if(curA == curB) {
                return curA;
            }
            curB = curB->next;
        }
        curA = curA->next;
    }
    return nullptr;
}

// Hashset or Unordered_Set Approach
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> st;
    ListNode *curA = headA, *curB = headB;
    while(curA) {
        st.insert(curA);
        curA = curA->next;
    }
    while(curB) {
        if(st.find(curB) != st.end()) {
            return curB;
        }
        curB = curB->next;
    }
    return nullptr;
}

int main() {
    return 0;
}