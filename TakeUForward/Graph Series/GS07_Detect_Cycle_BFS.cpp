#include<bits/stdc++.h>
using namespace std;

bool detectCycleUsingBFS(int n, vector<int> adj[]) {
    vector<int> visited(n, 0);
    
    // Storing {node, parent}
    queue<pair<int, int>> q;
    q.push({0, -1});
    visited[0] = 1;

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto v : adj[node]) {
            if(!visited[v]) {
                q.push({v, node});
                visited[v] = 1;
            }
            else {
                if(v != parent) {
                    return true;
                }
            }
        }
    }
    return false;
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

    detectCycleUsingBFS(n, adj);

    return 0;
}