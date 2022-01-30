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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr) return new TreeNode(val);
    
    TreeNode *node = root;
    while(node != nullptr) {
        if(val < node->val) {
            if(node->left == nullptr) {
                node->left = new TreeNode(val);
                break;
            }
            else node = node->left;
        }
        else if(val > node->val) {
            if(node->right == nullptr) {
                node->right = new TreeNode(val);
                break;
            }
            else node = node->right;
        }
    }
    return root;
    
}

int main() {
    return 0;
}