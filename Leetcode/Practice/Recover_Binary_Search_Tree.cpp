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

TreeNode *prev, *first, *middle, *second;

void inorderTraversal(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left);  
    if(prev!=nullptr && root->val < prev->val) {   
        if(first==nullptr) {
            first = prev;
            middle = root;
        }
        else {
            second = root;
        }
    }
    prev = root;
    inorderTraversal(root->right);
}

void recoverTree(TreeNode* root) {
    prev = first = middle = second = nullptr;
    inorderTraversal(root);
    
    if(second==nullptr) {
        swap(first->val, middle->val);
    }
    else {
        swap(first->val, second->val);
    }
}

int main() {
    return 0;
}