#include<bits/stdc++.h>
using namespace std;

void bfsOFGraph(int v, vector<int> adj[]) {
    vector<int> visited(v+1, 0);
    visited[0] = 1;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        // Iterate through neighbors
        for(auto n : adj[node]) {
            if(!visited[n]) {
                q.push(n);
                visited[n] = 1;
            }
        }
    }
    cout << endl;
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

    bfsOFGraph(n, adj);

    return 0;
}