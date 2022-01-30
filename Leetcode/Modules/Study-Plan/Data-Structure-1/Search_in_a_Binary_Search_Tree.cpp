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

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return NULL;
    
    TreeNode *subTree = NULL;
    if(val < root->val) 
        subTree = searchBST(root->left, val);
    else if(val > root->val) 
        subTree = searchBST(root->right, val);
    else 
        subTree = root;
    
    return subTree;
}

int main() {
    return 0;
}