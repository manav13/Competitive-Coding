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

    // vector = {size, minVal, maxVal}

    vector<int> postOrderTraversal(TreeNode *root) {
        if(root == nullptr) {
            return {0, INT_MAX, INT_MIN};
        }
        
        if(root->left == nullptr && root->right == nullptr)
            return {1, root->val, root->val};

        // Postorder = left right root

        vector<int> left = postOrderTraversal(root->left);
        vector<int> right = postOrderTraversal(root->right);

        // Check for valid BST
        // largest from left < nodeVal < smallest from right

        if(left[2] < root->val && root->val < right[1]) {
            // Valid BST
            int size = 1 + left[0] + right[0];
            int minVal = min(root->val, left[1]);
            int maxVal = max(root->val, right[2]);

            return {size, minVal, maxVal};
        }

        // If not a valid BST;
        int size = max(left[0], right[0]);
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        return {size, minVal, maxVal};
    
    }

    int largestBST(TreeNode* root) {
        vector<int> ans = postOrderTraversal(root);
        return ans[0];
    }
};