/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    // Merge two sorted arrays;
    Node* merge(Node* a, Node *b) {
        Node *temp = new Node(0);
        Node *res = temp;

        while(a!= nullptr && b != nullptr) {
            if(a->val < b->val) {
                temp->child = a;
                temp = temp->child;
                a = a->child;
            }
            else {
                temp->child = b;
                temp = temp->child;
                b = b->child;
            }
        }

        if(a != nullptr) {
            temp->child = a;
        }
        else temp->child = b;

        return res->child;
    } 

    Node* flatten(Node* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        head->next = flatten(head->next);

        head = merge(head, head->next);

        return head;
    }
};