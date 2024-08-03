#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int> adj[], vector<int> &visited, vector<int> &pathVisisted) {
    visited[i] = 1;
    pathVisisted = 1;

    for(auto node : adj[i]) {
        if(!visited[node]) {
            if(dfs(node, adj, visited, pathVisisted)) {
                return true;
            }
        }
        else {
            if(pathVisisted[node]) {
                return true;
            }
        }
    }

    pathVisisted[i] = 0;
    return false;
}

bool isCycle(vector<int> adj[]) {
    int n = adj.size();

    vector<int> visited(n, 0);
    vector<int> pathVisisted(n, 0);

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            if(dfs(i, adj, visited, pathVisited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    return 0;
}