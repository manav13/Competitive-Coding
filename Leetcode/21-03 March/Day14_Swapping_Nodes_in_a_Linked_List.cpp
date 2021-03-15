#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Iterative approach
/*ListNode* swapNodes(ListNode* head, int k) {
    int length = 0;
    ListNode* start = head;

    while(start) {
        ++length;
        start = start->next;
    }
    if(length == 1) return head;
    if(k>length/2) k = length + 1 - k;

    int val1, val2, count = 1;

    start = head;
    while(start) {
        if(count == k) {
            val1 = start->val;
        }
        if(count == length + 1 - k) {
            val2 = start->val;
            start->val = val1;
            break;
        }
        ++count;
        start = start->next;
    }

    start = head;
    count = 1;
    while(start) {
        if(count == k) {
            start->val = val2;
            break;
        }
        ++count;
        start = start->next;
    }
    return head;
}*/

// Array based approach
ListNode* swapNodes(ListNode* head, int k) {
    int length = 0;
    vector<int> arr;
    ListNode* start = head;

    while(start) {
        arr.push_back(start->val);
        ++length;
        start = start->next;
    }

    if(length == 1) return head;
    int k1 = k-1;
    int k2 = length - k;
    int temp = arr[k1];
    arr[k1] = arr[k2];
    arr[k2] = temp;

    start = head;
    int count = 0;
    while(start) {
        start->val = arr[count];
        start = start->next;
        ++count;
    }
    return head;
}

int main() {
    // cout << result << endl;
}