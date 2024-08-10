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

    TreeNode* findInorderSuccessor(TreeNode* root, int key) {
        TreeNode* suc = nullptr;

        while(root != nullptr) {
            if(key >= root->val) {
                root = root->right;
            }
            else {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};