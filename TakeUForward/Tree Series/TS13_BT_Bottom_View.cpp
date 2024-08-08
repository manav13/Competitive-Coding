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

vector<int> bottomViewOfBinaryTree(Node* root) {
    vector<int> result;
    if(root == nullptr) {
        return result;
    }

    // {node, level}
    queue<pair<Node*, int>> q;

    // {level : node->data}
    map<int, int> hash;

    // Insert root with level 0 to queue
    q.push({root, 0});

    while(!q.empty()) {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();

        hash[level] = node->data;
        
        if(node->left)
            q.push({node->left}, level-1);
        if(node->right)
            q.push({node->right}, level+1);
    }

    for(auto it : hash) {
        result.push_back(it.seond);
    }
    return result;
}

int main() {
    return 0;
}