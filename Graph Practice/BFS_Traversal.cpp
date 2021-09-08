#include<bits/stdc++.h>
using namespace std;

vector<int> bfs (int n, vector<int> adj[]) {
    vector<int> traversal;
    
    // Initialize vistor array
    vector<int> vis(n+1, 0);

    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                traversal.push_back(node);
                
                for(auto it : adj[node]) {
                    if(vis[it] == 0) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    return traversal;
}

int main() {
    int n,m;
    cin >> n >> m;
    
    // Forming adjacency list
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Traversing via BFS
    vector<int> traversal = bfs(n, adj);

    for(int i=0; i<n; i++) {
        cout << traversal[i] << " ";
    }
    cout << endl;
    return 0;
}