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

    TreeNode* findLastRight(TreeNode* node) {
        while(node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    TreeNode* helper(TreeNode* node) {
        if(node->left == nullptr)
            return node->right;

        if(node->right == nullptr)
            return node->left;
        
        TreeNode* rightChild = node->right;
        TreeNode* lastRightLeaf = findLastRight(node->left);
        lastRightLeaf->right = rightChild;
        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        
        if(root->val == key) {
            return helper(root);
        }

        TreeNode* cur = root;

        while(cur != nullptr) {
            if(key < cur->val) {
                if(cur->left != nullptr && cur->left->val == key) {
                    cur->left = helper(cur->left);
                    break;
                }
                cur = cur->left;
            }
            else {
                if(cur->right != nullptr && cur->right->val == key) {
                    cur->right = helper(cur->right);
                    break;
                }
                cur = cur->right;
            }
        }

        return root;
    }
};