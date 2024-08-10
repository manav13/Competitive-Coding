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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);

        TreeNode* cur = root;

        while(true) {
            if(val < cur->val) {
                if(cur->left == nullptr) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            }
            else {
                if(cur->right == nullptr) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }
        }

        return root;
    }
};