#include<bits/stdc++.h>
using namespace std;

// Mostly used for Directed Graphs, but works for undirected graphs as well.
// Dijkstra Algo does not work for NEGATIVE WEIGHTS AND NEGATIVE CYCLES
// Bellman ford works for this purpose
vector<int> bellmanFordAlgo(vector<vector<int>> edges, int n, int src) {
    // Algorithm: Relax all the edges N-1 times sequentially

    // edges are in the form: {u, v, w}
    vector<int> dist(n+1, INT_MX);
    dist[src] = 0;
    dist[0] = 0;

    // TC = O(V*E)
    for(int i=0; i<n-1;, i++) {
        // Iterate through all the edges
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Do Nth Iteration to check if there are Negative cycles
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return {-1};
        }
    }

    return dist;
}