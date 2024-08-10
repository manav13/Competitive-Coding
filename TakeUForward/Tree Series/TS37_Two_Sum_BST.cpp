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

class BSTIterator {

private:
    stack<TreeNode*> st;
    bool reverse = true;
    void pushAll(TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            if(reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

public:

    // Inorder = Left Value Right
    BSTIterator(TreeNode* root, bool isReverse) {
        // Store all the left nodes in stack
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();

        // Since we have visited the node, store the right
        if(reverse)
            pushAll(node->left);
        else
            pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:

    void traverse(TreeNode *root, vector<int> &path) {
        if(root == nullptr)
            return;
        // Inorder = left val right
        traverse(root->left, path);
        path.push_back(root->val);
        traverse(root->right, path);
    }

    bool findTarget(TreeNode* root, int k) {
        // vector<int> inorder; 
        // traverse(root, inorder);

        // int left = 0, right = inorder.size()-1;
        // while(left < right) {
        //     int sum = inorder[left] + inorder[right];
        //     if(sum == k)
        //         return true;
        //     else if(sum > k)
        //         right--;
        //     else
        //         left++;
        // }
        // return false;
        if(root == nullptr)
            return false;

        BSTIterator l(root, false);

        // before();
        BSTIterator r(root, true);

        int left = l.next();
        int right = r.next();

        while(left < right) {
            int sum = left + right;
            if(sum == k)
                return true;
            else if(sum < k)
                left = l.next();
            else
                right = r.next();
        }
        return false;
    }
};