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

void inOrderTraversal(TreeNode *node, vector<int> &path) {
    if(node == nullptr) return;
    
    inOrderTraversal(node->left, path);
    path.push_back(node->val);
    inOrderTraversal(node->right, path);
}

bool checkPath(vector<int> path) {
    int size = path.size();
    for(int i=1; i<size; i++) {
        if(path[i] <= path[i-1]) return false;
    }
    return true;
}

bool isValidBST(TreeNode* root) {        
    vector<int> path;
    inOrderTraversal(root, path);
    return checkPath(path);
}

int main() {
    return 0;
}