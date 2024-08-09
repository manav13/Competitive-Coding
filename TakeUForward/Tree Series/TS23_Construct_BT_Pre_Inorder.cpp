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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Preorder = VLR
        // Inorder = LVR

        // {nodeVal, index}
        unordered_map<int, int> inorderMap;
        int size = inorder.size();
        for(int i=0; i<size; i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildBT(preorder, 0, size-1, inorder, 0, size-1, inorderMap);
    }

    TreeNode* buildBT(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap) {
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildBT(preorder, preStart+1, preStart + numsLeft, inorder, inStart, inRoot-1, inorderMap);
        root->right = buildBT(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot+1, inEnd, inorderMap);

        return root;
    }
};