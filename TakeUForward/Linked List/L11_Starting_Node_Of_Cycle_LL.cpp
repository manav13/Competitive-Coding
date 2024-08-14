/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *detectCycle(ListNode *head) {
        // TC = O(N), SC = O(N)
        unordered_set<ListNode*> set;

        while(head != nullptr) {
            if(set.find(head) != set.end()) {
                return head;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        // TC = O(N), SC = O(1)
        ListNode* slow = head, *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                break;
        }
        if(fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // slow is the collision pointer
        ListNode* start = head;
        while(slow != start) {
            slow = slow->next;
            start = start->next;
        }
        return slow;
    }
};