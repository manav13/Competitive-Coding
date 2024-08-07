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

    int findHeight(TreeNode *root, int &diameter) {
        if(root == nullptr)
            return 0;
        
        int leftHeight = findHeight(root->left, diameter);
        int rightHeight = findHeight(root->right, diameter);

        int currentDiameter = leftHeight + rightHeight;

        diameter = max(currentDiameter, diameter);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findHeight(root, diameter);

        return diameter;
    }
};