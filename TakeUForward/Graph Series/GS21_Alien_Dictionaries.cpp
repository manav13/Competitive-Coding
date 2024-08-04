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

string findOrder(string dict[], int n, int k) {
    // form a grpah
    vector<int> adj[k];

    for(int i=0; i<n-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];

        int length = min(s1.size(), s2.size());
        for(int j=0; j<length; j++) {
            if(s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            }
        }
    }

    // Perform topological sort
    vector<int> topo = topoLogicalSort(adj);

    string ans = "";

    for(auto num : topo) {
        ans += char(num+'a');
    }
    return ans;
}

int main() {
    return 0;
}