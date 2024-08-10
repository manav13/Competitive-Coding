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

    void inorderTraversal(TreeNode* root, vector<int> &path) {
        if(root == nullptr)
            return;

        inorderTraversal(root->left, path);
        path.push_back(root->val);
        inorderTraversal(root->right, path);
    }
    
    bool check(TreeNode* node, long low, long high) {
        if(node == nullptr)
            return true;

        if(node->val <= low || node->val >= high) {
            return false;
        }

        bool leftCheck = check(node->left, low, node->val);
        bool rightCheck = check(node->right, node->val, high);

        return leftCheck && rightCheck;
    }

    bool isValidBST(TreeNode* root) {
        vector<int> path;
        inorderTraversal(root, path);

        for(int i=1; i<path.size(); i++) {
            if(path[i] <= path[i-1])
                return false;
        }
        return true;
    }
};