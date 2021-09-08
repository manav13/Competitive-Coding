#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &traversal) {
    traversal.push_back(node);
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            dfs(it, vis, adj, traversal);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    vector<int> traversal;
    vector<int> vis(n+1, 0);

    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) {
            dfs(i, vis, adj, traversal);
        }
    }

    return traversal;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Traversing via BFS
    vector<int> traversal = dfsOfGraph(n, adj);

    for(int i=0; i<n; i++) {
        cout << traversal[i] << " ";
    }
    cout << endl;
    return 0;
}