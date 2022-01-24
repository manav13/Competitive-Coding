#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode* p1 = head, *p2 = head;
    while(p1!=NULL && p2->next!=NULL) {
        p1 = p1->next;
        if(p2->next->next == NULL) return false;
        p2 = p2->next->next;
        if(p1 == p2) return true;
    }
    return false;
}

int main() {
    return 0;
}