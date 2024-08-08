#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root == nullptr)
        return;

    int child = 0;
    if(root->left)
        child += root->left->data;

    if(root->right)
        child += root->right->data;

    if(root->data <= child) {
        root->data = child;
    }
    else {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);  

    int total = 0;
    if(root->left)
        total += root->left->data;
    if(root->right)
        total += root->right->data;

    if(root->left || root->right)root->data = total;
}