#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    if(root == nullptr || root->data == start)
        return 0;
    
    // {Node: Parent}
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parentHash;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    BinaryTreeNode<int>* startNode;
    // Find the parents of each node;
    while(!q.empty()) {
        BinaryTreeNode<int>* parent = q.front();
        q.pop();
        if(parent->data == start) {
            startNode = parent;
        }
        if(parent->left) {
            q.push(parent->left);
            parentHash[parent->left] = parent;
        }

        if(parent->right) {
            q.push(parent->right);
            parentHash[parent->right] = parent;
        }
    }

    unordered_set<BinaryTreeNode<int>*> visited;
    visited.insert(startNode);
    
    q.push(startNode);
    int time = 0;
    while(!q.empty()) {

        time += 1;
        int size = q.size();

        for(int i=0; i<size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            // Parent
            if(parentHash.find(node) != parentHash.end() && visited.find(parentHash[node]) == visited.end()) {
                visited.insert(parentHash[node]);
                q.push(parentHash[node]);
            }
            // Left
            if(node->left && visited.find(node->left) == visited.end()) {
                visited.insert(node->left);
                q.push(node->left);
            }
            // Right
            if(node->right && visited.find(node->right) == visited.end()) {
                visited.insert(node->right);
                q.push(node->right);
            }
        }
    }
    return time-1;
}
