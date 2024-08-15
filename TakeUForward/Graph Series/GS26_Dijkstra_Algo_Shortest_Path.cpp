#include<bits/stdc++.h>
using namespace std;

// TC = O(E*logV)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // implement adjacency list
    vector<pair<int, int>> adj[n+1];

    for(auto edges : times) {
        int u = edges[0];
        int v = edges[1];
        int w = edges[2];
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    // Maintain a distance vector;
    vector<int> dist(n+1, INT_MAX);
    dist[0] = 0;
    dist[k] = 0;

    // Min Heap: {dist, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while(!pq.empty()) {
        int u = pq.top().second;
        int nodeDist = pq.top().first;

        pq.pop();

        for(auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(nodeDist + w < dist[v]) {
                dist[v] = nodeDist + w;
                pq.push({nodeDist + w, v});
            }
        }
    }

    int minTime = 0;
    for(auto time : dist) {
        if(time == INT_MAX)
            return -1;
        minTime = max(minTime, time);
    }

    return minTime;
}

int main() {
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    }; 
    int n = 4;
    int k = 2;

    cout << networkDelayTime(times, n, k) << endl;
    return 0;
}