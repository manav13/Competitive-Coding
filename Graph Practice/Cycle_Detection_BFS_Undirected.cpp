#include<bits/stdc++.h>
using namespace std;

bool bfsCycleCheck(int n, vector<int> adj[]) {
    vector<int> vis(n+1, 0);
    bool cycleDetected = false;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            queue< pair<int, int> > q;
            q.push({i, -1});
            vis[i] = 1;

            while(!q.empty()) {
                int node = q.front().first;
                int prev = q.front().second;
                q.pop();

                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if(vis[it]==1 && it!=prev) {
                        return true;
                    }
                }
            }
        }
    }
    return cycleDetected;
}

int main() {
    int n, edges;
    cin >> n >> edges;

    // Creating Adj list
    vector<int> adj[n+1];
    for(int i=0; i<edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycleDetected = bfsCycleCheck(n, adj);
    cout << (cycleDetected ? "True" : "False") << endl;
    return 0;
}