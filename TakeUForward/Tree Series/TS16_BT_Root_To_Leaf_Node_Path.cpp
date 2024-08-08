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

    bool isLeaf(TreeNode* node) {
        return node->right == nullptr && node->left == nullptr;
    }

    void traversal(TreeNode* root, vector<int> &path, vector<vector<int>> &ans) {
        if(root == nullptr)
            return;
        
        if(isLeaf(root)) {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        // Left Recursion
        traversal(root->left, path, ans);

        // Right recursion
        traversal(root->right, path, ans);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> ans;
        traversal(root, path, ans);

        vector<string> output;
        for(auto path : ans) {
            string s = "";
            int size = path.size();
            for(int i=0; i<size; i++) {
                if(i == size-1) {
                    s += to_string(path[i]);
                }
                else {
                    s += (to_string(path[i]) + "->");
                }
            }
            output.push_back(s);
        }
        return output;
    }
};