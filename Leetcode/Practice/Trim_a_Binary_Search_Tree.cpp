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

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(root == nullptr) return root;
    if(root->val < low) {
        root = trimBST(root->right, low, high);
        return root;
    }
    else if(root->val > high) {
        root = trimBST(root->left, low, high);
        return root;
    }
    else {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
    return nullptr;
}

int main() {
    return 0;
}