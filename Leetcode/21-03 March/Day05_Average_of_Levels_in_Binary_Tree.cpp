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
class Solution {
public:
    
    // void BFS(TreeNode* root, vector<double>& avg) {
    //     if(root == nullptr || (root->right == nullptr && root->left == nullptr)) return;
    //     else {
    //         if(root->right == nullptr && root->left != nullptr) {
    //             avg.push_back(root->left->val);
    //             BFS(root->left, avg);
    //             return;
    //         }
    //         else if(root->left == nullptr && root->right != nullptr) {
    //             avg.push_back(root->right->val);
    //             BFS(root->right, avg);
    //             return;
    //         }
    //         else {
    //             double avg_val = (double)((root->left)->val + (root->right)->val)/2;
    //             avg.push_back(avg_val);
    //             BFS(root->left, avg);
    //             BFS(root->right, avg);
    //             // double s1 = avg.back();
    //             // avg.pop_back();
    //             // double s2 = avg.back();
    //             // avg.pop_back();
    //             // avg_val = (s1*2 + s2*2)/2;
    //             // avg.push_back(avg_val);
    //             return;
    //         }
    //     }
    // }

    void BFS(TreeNode* root, vector< vector<int> >& values, int depth) {
        if(root == nullptr) return;
        else if(depth == 0) {
            vector<int> temp;
            temp.push_back(root->val);
            values.push_back(temp);
            depth++;
            BFS(root->left, values, depth);
            BFS(root->right, values, depth);
        }
        else {
            if(values.size()-1 < depth) {
                vector<int> temp;
                temp.push_back(root->val);
                values.push_back(temp);
                depth++;
                BFS(root->left, values, depth);
                BFS(root->right, values, depth);
            }
            else {
                values[depth].push_back(root->val);
                depth++;
                BFS(root->left, values, depth);
                BFS(root->right, values, depth);
            }
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        vector< vector<int> > values;
        BFS(root, values, 0);
        for(int i=0; i<values.size(); i++) {
            double sum = 0;
            for(int num : values[i]) {
                sum += num;
            }
            double avgVal = (double) sum/values[i].size();
            avg.push_back(avgVal);
        }
        return avg;
    }
};