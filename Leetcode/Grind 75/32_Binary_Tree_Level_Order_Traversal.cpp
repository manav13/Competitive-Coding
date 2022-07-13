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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root==nullptr) return result;
        queue<TreeNode*> qt;
        qt.push(root);
        
        while(!qt.empty()) {
            
            vector<int> midResult;
            int size = qt.size();
            for(int i=0; i<size; i++) {
                TreeNode *node = qt.front();
                qt.pop();
                
                if(node->left != nullptr) qt.push(node->left);
                if(node->right != nullptr) qt.push(node->right);
                
                midResult.push_back(node->val);
            }
            
            result.push_back(midResult);
        }
        return result;
    }
};

int main() {
    return 0;
}