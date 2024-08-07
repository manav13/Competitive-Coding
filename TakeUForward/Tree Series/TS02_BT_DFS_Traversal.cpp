#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorderTraversal(Node *root) {
    if(root == nullptr)
        return;

    // Left Root Right
    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

vector<int> inorderTraversalIterative(Node *root) {
    vector<int> result;
    stack<Node*> st;
    st.push(root);

    if(root == nullptr) {
        return result;
    }

    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true) {
        if(node != nullptr) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty()) {
                break;
            }
            node = st.top();
            result.push_back(node->val);
            st.pop();
            node = node->right;
        }
    }
    return result;
}

void preorderTraversal(Node *root) {
    if(root == nullptr)
        return;

    // Root Left Right
    cout << root->val << endl;
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

void preorderTraversalIterative(Node *root) {
    if(root == nullptr) {
        return;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node *node = st.top();
        st.pop();

        cout << node->val << " ";

        if(node->right != nullptr) {
            st.push(node->right);
        }
        if(node->left != nullptr) {
            st.push(node->left);
        }
    }
}

void postorderTraversal(Node *root) {
    if(root == nullptr)
        return;

    // Left Right Root
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->val << endl;
}

int main() {
    return 0;
}