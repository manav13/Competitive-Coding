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

void inorderTraversal(TreeNode* root, int k, int& level, int &ans) {
    if(root == nullptr || level == k) {
        return;
    }
    
    inorderTraversal(root->left, k, level, ans);
    
    if(level == k) return;
    level++; 
    ans = root->val;
    
    inorderTraversal(root->right, k, level, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = 0, level = 0;
    inorderTraversal(root, k, level, ans);
    return ans;
}

int main() {
    return 0;
}