#include<bits/stdc++.h>
using namespace std;

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        
        // Swap the node;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Call on left and right subtree..
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

int main() {
    return 0;
}