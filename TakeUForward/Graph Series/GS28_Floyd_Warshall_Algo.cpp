#include<bits/stdc++.h>
using namespace std;

// Dijkstra & Bellman ford Algo are for single sources
// Floyd Warshall is for multi-source nodes.
// Detects negative cycle as well
vector<vector<int>> floydWarshall(vector<vector<int>> edges, int n) {
    
    vector<vector<int>> cost(n, vector<int>(n, 1e9));
    for(int i=0; i<n; i++) {
        cost[i][i] = 0;
    }

    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        cost[u][v] = wt;
        // if undirected, add cost[v][u] = wt;
    }

    for(int node=0; node<n; node++) {
        // This means if we want to move from u->v, then cost[u][v] = cost[u][node] + cost[node][v];
        for(int u=0; u<n; u++) {
            for(int v=0; v<n; v++) {
                cost[u][v] = min(cost[u][v], cost[u][node] + cost[node][v]);
            }
        }
    }

    return cost;
}