/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // TC = O(N), SC = O(N)
        if(head == nullptr)
            return nullptr;
        // {Old, New}
        unordered_map<Node*, Node*> hash;

        Node *node = head;
        while(node != nullptr) {
            Node *newNode = new Node(node->val);
            hash[node] = newNode;
            node = node->next;
        }

        Node *newHead = hash[head];
        node = head;
        // Copy all properties
        while(node != nullptr) {
            Node *newNode = hash[node];
            newNode->next = hash[node->next];
            newNode->random = hash[node->random];
            node = node->next;
        }

        return newHead;
    }

    Node* copyRandomList(Node* head) {
        // TC = O(N), SC = O(1)
        if(head == nullptr)
            return nullptr;

        Node *cur = head, *next = nullptr;

        // Step 1: create deep copy nodes
        while(cur != nullptr) {
            next = cur->next;
            // Create deep copy node
            Node *deepCur = new Node(cur->val);

            cur->next = deepCur;
            deepCur->next = next;
            cur = next;
        }

        // Step 2: assign random pointers
        cur = head;

        while(cur != nullptr) {
            if(cur->random != nullptr)
                cur->next->random = cur->random->next;

            cur = cur->next->next;
        }

        // Step 3: Remove the connection between old and new node;
        cur = head;
        Node *newHead = new Node(0);
        Node *copy = newHead;

        while(cur != nullptr) {
            next = cur->next->next;
            copy->next = cur->next;

            cur->next = next;
            copy = copy->next;
            cur = next;
        }

        return newHead->next;
    }
};