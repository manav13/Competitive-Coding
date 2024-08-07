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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;

        // {Node, {row, col}}
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        // {col: {row: {nodeValues}}}
        map<int, map<int, multiset<int>>> hash;

        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;

                q.pop();

                if(node->left)
                    q.push({node->left, {row+1, col-1}});
                if(node->right)
                    q.push({node->right, {row+1, col+1}});
                
                hash[col][row].insert(node->val);
            }
        }

        for(auto p : hash) {
            vector<int> col;
            for(auto q : p.second) {
                for(auto val : q.second) {
                    col.push_back(val);
                }
            }
            result.push_back(col);
        }
        return result;
    }
};