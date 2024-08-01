#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &traversal) {
    traversal.push_back(node);
    visited[node] = 1;

    for(auto it : adj[node]) {
        if(!visited[it]) {
            dfs(it, adj, visited, traversal);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    vector<int> visited(v+1, 0);
    vector<int> traversal;
    dfs(0, adj, visited, traversal);
    return traversal;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsOFGraph(n, adj);

    return 0;
}