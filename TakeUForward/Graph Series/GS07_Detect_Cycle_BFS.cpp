#include<bits/stdc++.h>
using namespace std;

bool detectCycleUsingBFS(int n, vector<int> adj[]) {
    vector<int> visited(n, 0);
    
    queue<pair<int, int>> q;
    q.push({0, -1});
    visited[0] = 1;

    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        for(auto v : adj[node.first]) {
            if(!visited[v]) {
                q.push({v, node.first});
                visited[v] = 1;
            }
            else {
                if(v != node.first) {
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