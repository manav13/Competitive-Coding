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
    // TC = O(n) and SC = O(1)
    vector<int> morrisTraversal(TreeNode* root) {
        vector<int> result;

        // Return empty result if root is null
        if(root == nullptr) {
            return result;
        }

        TreeNode* cur = root;

        while(cur != nullptr) {
            // Total of 3 cases:
            
            // Case 1: if left is null, then it is root
            if(cur->left == nullptr) {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else {
                // Case 2: If there is cur->left, 
                // then create a link/thread between right-most node to the root;
                TreeNode* prev = cur->left;
                while(prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }

                // If prev->right is null, means there is no link/thread to the root, so create it
                if(prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                }
                // If prev->right link is there, means there is a link to root
                // So remove the link and goto right subtree
                else {
                    prev->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        return morrisTraversal(root);
    }
};