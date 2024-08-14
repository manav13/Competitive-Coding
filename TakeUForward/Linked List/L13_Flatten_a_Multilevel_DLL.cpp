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

Node *head2, *last;

public:

    void insert(int val) {
        Node* node = new Node(val);
        last->next = node;
        node->prev = last;
        last = last->next;
    }

    void dfs(Node* node) {
        if (node == nullptr)
            return;
        
        // insert to new DLL
        insert(node->val);
        dfs(node->child);
        dfs(node->next);
    }

    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;

        head2 = new Node();
        last = head2;
        dfs(head);

        head2->next->prev = nullptr;

        return head2->next;
    }
};