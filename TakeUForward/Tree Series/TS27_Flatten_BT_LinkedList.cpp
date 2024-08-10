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
    // Preorder = VLR
    void dfs(TreeNode* node, vector<TreeNode*> &list) {
        if(node == nullptr)
            return;
        list.push_back(node);
        dfs(node->left, list);
        dfs(node->right, list);
    }

    void flatten(TreeNode* root) {
        // Do preorder traversal and store all the references of nodes in a vector;
        vector<TreeNode*> list;
        dfs(root, list);

        // Rearrange the nodes using the list
        // Left = nullptr;
        // Right = current nodes next;
        int size = list.size();
        for(int i=0; i<size-1; i++) {
            list[i]->left = nullptr;
            list[i]->right = list[i+1];
        }
    }

    void flatten2(TreeNode* root) {
        TreeNode* cur = root;

        while(cur != nullptr) {
            if(cur->left != nullptr) {
                TreeNode* prev = cur->left;

                while(prev->right != nullptr) {
                    prev = prev->right;
                }

                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};