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

void traversal(TreeNode *node, int level, int &depth) {
    if(node == NULL) return;
    
    if(level>depth) depth = level;
    
    if(node->left != NULL) traversal(node->left, level+1, depth);
    if(node->right != NULL) traversal(node->right, level+1, depth);
    return;
}

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    int depth = 1;
    traversal(root, 1, depth);
    return depth;
}

int main() {
    return 0;
}