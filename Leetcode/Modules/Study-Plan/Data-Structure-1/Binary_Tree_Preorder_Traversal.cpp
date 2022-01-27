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

void traversal(TreeNode* node, vector<int> &ans) {
    //Base Case
    if(node == NULL) return;
    
    // Calculation - VLR
    ans.push_back(node->val);
    traversal(node->left, ans);
    traversal(node->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    if(root == NULL) return {};
    vector<int> ans;
    traversal(root, ans);
    return ans;
}

int main() {
    return 0;
}