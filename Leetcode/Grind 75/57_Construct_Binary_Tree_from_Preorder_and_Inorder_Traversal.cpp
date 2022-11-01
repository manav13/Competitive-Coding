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
    
    TreeNode* constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &hash) {
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int index = hash[preorder[preStart]];
        int numsLeft = index - inStart;
        
        root->left = constructTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, index-1, hash);
        root->right = constructTree(preorder, preStart+numsLeft+1, preEnd, inorder, index+1, inEnd, hash);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> hash;
        int size = inorder.size();
        for(int i=0; i<size; i++) {
            hash[inorder[i]] = i;
        }
        
        return constructTree(preorder, 0, size-1, inorder, 0, size-1, hash);
    }
};