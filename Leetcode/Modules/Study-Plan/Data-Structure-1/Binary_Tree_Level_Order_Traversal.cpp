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

void recursiveTraversal(TreeNode *node, int level, vector<vector<int>> &ans) {
    if(node == nullptr) return;
    
    if(ans.size() <= level) {
        vector<int> newLevel;
        newLevel.push_back(node->val);
        ans.push_back(newLevel);
    }
    else {
        ans[level].push_back(node->val);
    }
    
    if(node->left!=nullptr) recursiveTraversal(node->left, level+1, ans);
    if(node->right!=nullptr) recursiveTraversal(node->right, level+1, ans);
    return;
    }

vector<vector<int>> BFSTraversal(TreeNode *root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> currentLevel;
        for(int i=0; i<size; i++) {  
            TreeNode *cur = q.front();
            currentLevel.push_back(cur->val);
            q.pop();
            
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
        ans.push_back(currentLevel);
    }
    return ans;
}

int main() {
    return 0;
}