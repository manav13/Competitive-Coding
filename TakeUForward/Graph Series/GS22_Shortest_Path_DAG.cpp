#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st) {
    visited[node] = 1;

    for(auto adjNode : adj[node]) {
        if(!visited[adjNode.first]) {
            topologicalSort(adjNode.first, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, vector<vector<int>> graph) {

    // Graph is in the form of {u, v, weight}
    // Lets convert it to adjacency list
    vector<pair<int, int>> adj[n];
    for(auto edge : graph) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        adj[u].push_back({v, weight});
    }

    // Step1: Perform topological sort using DFS
    stack<int> st;
    vector<int> visited(n, 0);

    // Assuming the src node to be 0 (zero)
    // O(N+E)
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            topologicalSort(i, adj, visited, st);
        }
    }

    // Step2: pop the nodes from stack and relax the edges
    vector<int> dist(n, 1e9);

    // Mark the src node dist to be zero
    dist[0] = 0;

    // O(N+E)
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        int distNode = dist[node];

        for(auto adjNode : adj[node]) {
            int distFromU = adjNode.second + distNode;

            dist[adjNode] = min(distFromU, dist[adjNode]);
        }
    }

    return dist;
    
}

int main() {
    return 0;
}