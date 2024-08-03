#include<bits/stdc++.h>
using namespace std;

vector<int> topoLogicalSort(vector<int> adj[]) {
    int n = adj.size();
    vector<int> indegree(n, 0);

    // Create indegree array
    for(int i=0; i<n; i++) {
        for(auto node : adj[i]) {
            indegree[node] += 1;
        }
    }

    queue<int> q;
    // Push all the node in queue whose indegree = 0
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto adjNode : adj[node]) {
            // Reduce indegree when visited
            indegree[adjNode]--;

            // If indegree becomes zero then push to queue
            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    return topo;
}

int main() {
    return 0;
}