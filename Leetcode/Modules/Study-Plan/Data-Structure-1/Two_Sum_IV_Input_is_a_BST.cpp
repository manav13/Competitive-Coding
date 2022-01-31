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

void inorderTraverse(TreeNode *node, vector<int> &path) {
    if(node == nullptr) return;
    
    inorderTraverse(node->left, path);
    path.push_back(node->val);
    inorderTraverse(node->right, path);
    return;
}

bool findTarget(TreeNode* root, int k) {
    vector<int> path;
    inorderTraverse(root, path);
    int size = path.size();
    for(int i=0; i<size; i++) {
        if(binary_search(path.begin()+i+1, path.end(), k-path[i])) return true;
    }
    return false;
}

int main() {
    return 0;
}