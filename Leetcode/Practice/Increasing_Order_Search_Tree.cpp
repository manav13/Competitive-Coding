#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* cur = new TreeNode(0);

void inorderTraversal(TreeNode* root) {
    if(root == nullptr) return;
    
    inorderTraversal(root->left);
    
    root->left = nullptr;
    cur->right = root;
    cur = cur->right;
    
    inorderTraversal(root->right);
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode* ans = cur;
    inorderTraversal(root);
    return ans->right;
}

int main() {
    return 0;
}