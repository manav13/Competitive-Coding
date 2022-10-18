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

    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        
        if(root != nullptr)
            q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            TreeNode* lastNode;
            
            while(size--) {
                lastNode = q.front();
                q.pop();
                
                if(lastNode->left != nullptr) q.push(lastNode->left);
                if(lastNode->right != nullptr) q.push(lastNode->right);
            }
            
            result.push_back(lastNode->val);
        }
        return result;
    }
};

int main() {
    return 0;
}