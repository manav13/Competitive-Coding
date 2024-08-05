#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int src, int n, vector<int> adj[]) {
    
    // Queue stores in the form of {node, dist}
    queue<pair<int, int>> q;
    vector<int> dist(n, 1e9);

    q.push({src, 0});
    dist[src] = 0;

    while(!q.empty()) {
        int u = q.front().first;
        int distU = q.front().second;
        q.pop();

        for(auto v : adj[u]) {
            int distV = distU + 1;
            // dist[v] = min(distV, dist[v]);

            if(distV < dist[v]) {
                dist[v] = distV;
                q.push({v, distV});
            }
        }
    }

    return dist;
}

int main() {
    return 0;
}