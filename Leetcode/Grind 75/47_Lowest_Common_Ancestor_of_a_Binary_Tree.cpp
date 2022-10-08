#include<bits/stdc++.h>
using namespace std;

// time - O(n) and Space - O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q)
        return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if(left != nullptr && right == nullptr)
        return left;
    else if(left == nullptr && right != nullptr)
        return right;
    else if(left != nullptr && right != nullptr)
        return root;
    else
        return nullptr;
}


// Time - O(n) and Space - O(n)
bool getPaths(TreeNode* root, TreeNode *node, vector<TreeNode*> &path) {
    if(root == nullptr)
        return false;
    
    path.push_back(root);
    
    if(root == node)
        return true;
    
    bool leftPath = getPaths(root->left, node, path);
    bool rightPath = getPaths(root->right, node, path);
    
    if(!leftPath && !rightPath)
        path.pop_back();
    return leftPath || rightPath;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pPath, qPath;
    getPaths(root, p, pPath);
    getPaths(root, q, qPath);
    
    int size = min(pPath.size(), qPath.size());
    int i;
    for(i=0; i<size; i++) {
        if(pPath[i] != qPath[i])
            break;
    }
    return pPath[i-1];
}

int main() {
    return 0;
}