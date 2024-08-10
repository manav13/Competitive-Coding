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

    TreeNode* build(vector<int> &preorder, int &index, int upper) {
        if(index == preorder.size() || preorder[index] > upper) {
            return nullptr;
        }

        TreeNode *node = new TreeNode(preorder[index]);
        index++;
        node->left = build(preorder, index, node->val);
        node->right = build(preorder, index, upper);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, upper = INT_MAX;
        return build(preorder, index, upper);
    }
};