#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);
        int size;
        
        vector<vector<int>> result;
        
        while(!q.empty()) {
            size = q.size();
            vector<int> levelNodes;
            while(size--) {
                TreeNode *node = q.front();
                q.pop();
                levelNodes.push_back(node->val);
                
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            result.push_back(levelNodes);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;
}