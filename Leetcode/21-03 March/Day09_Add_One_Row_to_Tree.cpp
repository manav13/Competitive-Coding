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

class Solution {
public:
    void BFS(TreeNode* root, int v, int d, int cur_depth) {
        if(root == nullptr) return;
        if(cur_depth == (d-1)) {
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            
            l->left = root->left;
            r->right = root->right;
            
            root->left = l;
            root->right = r;
            
            return; 
        }
        else {
            ++cur_depth;
            BFS(root->left, v, d, cur_depth);
            BFS(root->right, v, d, cur_depth);
            return;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int cur_depth = 1;
        TreeNode* head = root;
        if(d == 1) {
            TreeNode* n1 = new TreeNode(v);
            n1->left = root;
            root = n1;
            return root;
        }
        else {
            BFS(root, v, d, 1);
            return head;
        }
    }
};