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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool left2Right = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if(!left2Right) {
                vector<int> reverseLevel;
                for(int i=level.size()-1; i>=0; i--) {
                    reverseLevel.push_back(level[i]);
                }
                result.push_back(reverseLevel);
            }
            else {
                result.push_back(level);
            }
            left2Right = !left2Right;
        }

        return result;
    }
};