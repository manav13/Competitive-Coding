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
    
    // InorderTraversal approach
    void inorderTraversal(TreeNode *root, vector<int> &path, bool &isValid) {
        if(root == nullptr || !isValid)
            return;
        
        inorderTraversal(root->left, path, isValid);
        
        if(!path.empty()) {
            if(path.back() >= root->val) {
                isValid = false;
                return;
            }
        }
        path.push_back(root->val);
        
        inorderTraversal(root->right, path, isValid);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> path;
        bool isValid = true;
        inorderTraversal(root, path, isValid);
        return isValid;
    }
};

// Optimal way - setting left and right limits
class Solution {
public:
    
    bool valid(TreeNode *root, long long int left, long long int right) {
        if(root == nullptr)
            return true;
        
        if (left >= root->val || root->val >= right) {
            return false;
        }
        
        return (valid(root->left, left, root->val) && valid(root->right, root->val, right));
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    return 0;
}