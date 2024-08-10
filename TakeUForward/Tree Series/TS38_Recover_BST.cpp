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

private:

    TreeNode *prev;
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;

public:

    void inorderTraversal(TreeNode *root) {
        if(root == nullptr)
            return;

        // Left Val Right
        inorderTraversal(root->left);

        if(prev != nullptr && root->val < prev->val) {
            if(first == nullptr) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        inorderTraversal(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorderTraversal(root);

        if(last == nullptr) {
            // Swap first and middle
            int temp = first->val;
            first->val = middle->val;
            middle->val = temp;
        }
        else {
            // Swap first and last
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
    }
};