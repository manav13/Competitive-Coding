#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    
    while(list1!=NULL && list2!=NULL) {
        if(list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        }
        else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    while(list1!=NULL) {
        cur->next = list1;
        list1 = list1->next;
        cur = cur->next;
    }
    while(list2!=NULL) {
        cur->next = list2;
        list2 = list2->next;
        cur = cur->next;
    }
    return head->next;
}

int main() {
    return 0;
}