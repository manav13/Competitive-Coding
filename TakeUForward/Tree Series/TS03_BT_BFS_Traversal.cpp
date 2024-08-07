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

vector<vector<int>> BFSTraversal(Node *root) {
    vector<vector<int>> ans;
    if(root == nullptr) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        vector<int> level;
        for(int i=0; i<size; i++) {
            Node *node = q.front();
            q.pop();
            level.push_back(node->val);

            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    return 0;
}