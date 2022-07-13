#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* node, unordered_map<Node*, Node*> &hash) {
        if(hash.find(node) != hash.end()) {
            return hash[node];
        }
        
        Node* copy = new Node(node->val);
        hash[node] = copy;
        for(auto neigh : node->neighbors) {
            copy->neighbors.push_back(dfs(neigh, hash));
        }
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> hash;
        return dfs(node, hash);
    }
};

int main() {
    return 0;
}