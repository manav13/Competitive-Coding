#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    // Adjacency Matrix for undirected graph
    int adj[n+1][n+1];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Adjacency List for undirected graph
    vector<int> adj_list[n+1];
    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    //Adjacency List for weighted undirected graphs
    vector< pair<int, int> > adj_list_weighted[n+1];

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list_weighted[u].push_back({v, w});
        adj_list_weighted[v].push_back({u, w});
    }

    return 0;
} 