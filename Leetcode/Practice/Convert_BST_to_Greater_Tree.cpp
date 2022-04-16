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

void greaterTraversal(TreeNode* root, int& sum) {
    if(root == nullptr) return;
    
    // RVL traversal
    greaterTraversal(root->right, sum);
    
    root->val += sum;
    sum = root->val;
    
    greaterTraversal(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    greaterTraversal(root, sum);
    return root;
}

int main() {
    return 0;
}