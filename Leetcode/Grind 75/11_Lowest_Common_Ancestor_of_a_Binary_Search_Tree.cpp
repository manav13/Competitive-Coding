#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root->val == p->val || root->val == q->val) return root;
        
        if((p->val < root->val && root->val < q->val) || (q->val < root->val && root->val < p->val)) return root;
        else if(p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        else if(q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        
        return root;
    }
};

int main() {
    return 0;
}