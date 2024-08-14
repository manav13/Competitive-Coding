/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode *node) {
        ListNode *prev = nullptr, *next = nullptr;
        while(node != nullptr) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // TC = O(N), SC = O(N)
        vector<int> nums;
        while(head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        int start = 0, end = nums.size()-1;
        while(start <= end) {
            if(nums[start] != nums[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        // TC = O(N), SC = O(1)
        ListNode *fast = head, *slow = head;

        // Find the middle of LL
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the right half
        slow->next = reverse(slow->next);

        // move slow to start of right half
        slow = slow->next;

        // Check for left and right half to be equal or not;
        ListNode *cur = head;
        while(slow != nullptr) {
            if(cur->val != slow->val) {
                return false;
            }
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
};