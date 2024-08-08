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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;

        // {Node, index}
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int width = 1;
        while(!q.empty()) {
            int size = q.size();
            long long prevIndex = q.front().second;
            int minIndex, maxIndex;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second - prevIndex;
                q.pop();

                if(i == 0) {
                    minIndex = index;
                }
                if(i == size-1) {
                    maxIndex = index;
                }

                if(node->left) {
                    q.push({node->left, index*2+1});
                }
                
                if(node->right) {
                    q.push({node->right, index*2+2});
                }
            }
            width = max(width, maxIndex - minIndex + 1);
        }

        return width;
    }
};