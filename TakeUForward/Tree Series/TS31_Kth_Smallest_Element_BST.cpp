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

    void inorderTraversal(TreeNode* node, int k, int &nodeVal, int &count) {
        if(node == nullptr)
            return;

        // Left Node Right
        inorderTraversal(node->left, k, nodeVal, count);
        count++;
        if(k == count) {
            nodeVal = node->val;
        }
        inorderTraversal(node->right, k, nodeVal, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans, count = 0;
        inorderTraversal(root, k, ans, count);
        return ans;
    }
};