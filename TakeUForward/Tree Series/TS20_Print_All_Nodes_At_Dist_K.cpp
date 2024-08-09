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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
            return {target->val};
        
        // {Node: Parent}
        unordered_map<TreeNode*, TreeNode*> parentHash;

        queue<TreeNode*> q;
        q.push(root);

        // Find the parents of each node;
        while(!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            if(parent->left) {
                q.push(parent->left);
                parentHash[parent->left] = parent;
            }

            if(parent->right) {
                q.push(parent->right);
                parentHash[parent->right] = parent;
            }
        }

        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        q.push(target);
        int dist = 0;
        vector<int> result;
        while(!q.empty()) {

            dist += 1;
            int size = q.size();

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Parent
                if(parentHash.find(node) != parentHash.end() && visited.find(parentHash[node]) == visited.end()) {
                    visited.insert(parentHash[node]);
                    if(dist==k) {
                        result.push_back(parentHash[node]->val);
                    }
                    else{
                        q.push(parentHash[node]);
                    }
                }
                // Left
                if(node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    if(dist==k) {
                        result.push_back(node->left->val);
                    }
                    else{
                        q.push(node->left);
                    }
                }
                // Right
                if(node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    if(dist==k) {
                        result.push_back(node->right->val);
                    }
                    else{
                        q.push(node->right);
                    }
                }
            }
        }
        return result;
    }
};