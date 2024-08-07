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


void addLeftBoundary(Node* root, vector<int> &result) {
    Node *node = root->left;
    while(node) {
        if(!isLeaf(node))
            result.push_back(node->data);
        if(node->left)
            node = node->left;
        else
            node = node->right;
    }
}

void addRightBoundary(Node* root, vector<int> &result) {
    Node *node = root->right;
    vector<int> temp;
    while(node) {
        if(!isLeaf(node))
            temp.push_back(node->data);
        if(node->right)
            node = node->right;
        else
            node = node->left;
    }

    for(int i=temp.size()-1; i>=0; i--) {
        result.push_back(temp[i]);
    }
}

void addLeafNodes(Node* root, vector<int> &result) {
    if(isLeaf(root))
        result.push_back(root->data);

    if(root->left)
        addLeafNodes(root->left, result);
    if(root->right)
        addLeafNodes(root->right, result);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> result;
    if(root == nullptr)
        return result;

    if(!isLeaf(root))
        result.push_back(root->data);
    
    addLeftBoundary(root, result);
    addLeafNodes(root, result);
    addRightBoundary(root, result);
}