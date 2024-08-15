#include<bits/stdc++.h>
using namespace std;

// Given an undirected weighted graph with N nodes and M edges
// Spanning Tree = tree in which there are N nodes and N-1 edges and all nodes are reachable from each other
// MST = Spanning tree which has minimum sum of all edge weights.

int MST_PrimsAlgo(vector<pair<int, int>> adj[], int n) {
    // TC = E log E
    vector<vector<int>> mst;
    vector<int> visited(n, 0);

    // Min heap = {wt, node, parent}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, 0, -1});
    int sum = 0;
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if(!visited[node]) {
            visited[node] =  1;
            if(parent != -1) {
                mst.push_back({parent, node});
                sum += wt;
            }

            // Iterate through adj nodes
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!visited[adjNode]) {
                    pq.push({edgeWt, adjNode, node});
                }
            }
        }
        
    }

    // return mst;
    return sum;
}

int main() {
    return 0;
}