#include<bits/stdc++.h>
using namespace std;

bool detectCycleUsingDFS(int node, int parent, vector<int> adj[], vector<int> &visited) {
    visited[node] = 1;

    bool ans = false;

    for(auto adjacentNode : adj[node]) {
        if(adjcentNode != parent) {
            if(!visited[adjacentNode]) {
                ans = ans || detectCycleUsingDFS(adjacentNode, node, adj, visited);
            }
            else {
                return true;
            }
        }
    }

    return ans;
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

    vector<int> visited(n, 0);

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            detectCycleUsingDFS(i, -1, adj, visited);
        }
    }

    return 0;
}