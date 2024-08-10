/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ceil(TreeNode* node, int val) {
        if(node == nullptr)
            return -1;

        TreeNode* cur = node;
        int ceil = INT_MAX;
        while(cur != nullptr)
        {
            if(cur->val == val)
                return val;
            
            if(val < cur->val) {
                ceil = cur->val;
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return ceil == INT_MAX ? -1 : ceil;
    }

    int floor(TreeNode* node, int val) {
        if(node == nullptr)
            return -1;

        TreeNode* cur = node;
        int floor = INT_MIN;
        while(cur != nullptr)
        {
            if(cur->val == val)
                return val;
            
            if(val > cur->val) {
                floor = cur->val;
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }
        return floor == INT_MIN ? -1 : floor;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> result;

        for(auto val : queries) {
            vector<int> answer;

            TreeNode* cur = root;
            int floor = -1;
            int ceil = -1;

            while(cur != nullptr)
            {
                if(cur->val == val) {
                    floor = val;
                    ceil = val;
                    break;
                }
                if(val > cur->val) {
                    floor = cur->val;
                    cur = cur->right;
                }
                else {
                    ceil = cur->val;
                    cur = cur->left;
                }
            }
            result.push_back({floor, ceil});
        }

        return result;
    }
};