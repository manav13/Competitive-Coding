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
    
    int checkHeight(TreeNode* root, bool &ans) {
        if(ans == false || root == nullptr) return 0;
        
        int left = checkHeight(root->left, ans);
        int right = checkHeight(root->right, ans);
        
        if(abs(left-right) > 1) ans = false;
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        checkHeight(root, ans);
        return ans;
    }
};

int main() {
    return 0;
}