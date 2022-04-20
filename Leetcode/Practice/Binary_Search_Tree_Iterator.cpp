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

// Solved using Stack, TC = O(1), SC = O(height)
class BSTIterator {
public:
    
    stack<TreeNode*> st;
    
    void leftTraversal(TreeNode* root) {
        if(root==nullptr) return;
        st.push(root);
        leftTraversal(root->left);
    }
    
    BSTIterator(TreeNode* root) {
        leftTraversal(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(node->right!=nullptr) leftTraversal(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};


// Solved using Queue - not optimal
class BSTIterator {
public:
    
    queue<int> treeQueue;
    
    void inorderTraversal(TreeNode* root) {
        if(root == nullptr) return;
        
        inorderTraversal(root->left);
        treeQueue.push(root->val);
        inorderTraversal(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    
    int next() {
        int ans = treeQueue.front();
        treeQueue.pop();
        return ans;
    }
    
    bool hasNext() {
        return !treeQueue.empty();
    }
};

int main() {
    return 0;
}