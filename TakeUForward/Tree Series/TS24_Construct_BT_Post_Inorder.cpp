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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Postorder = LRV
        // Inorder = LVR

        // {nodeVal, index}
        unordered_map<int, int> inorderMap;
        int size = inorder.size();
        for(int i=0; i<size; i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildBT(postorder, 0, size-1, inorder, 0, size-1, inorderMap);
    }

    TreeNode* buildBT(vector<int> postorder, int postStart, int postEnd, vector<int> inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap) {
        if(postStart > postEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildBT(postorder, postStart, postStart + numsLeft-1, inorder, inStart, inRoot-1, inorderMap);
        root->right = buildBT(postorder, postStart + numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inorderMap);

        return root;
    }
};