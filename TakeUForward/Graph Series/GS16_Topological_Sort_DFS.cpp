#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st) {
    visited[node] = 1;

    for(auto adjNode : adj[node]) {
        if(!visited[adjNode]) {
            dfs(adjNode, adj, visited, st);
        }
    }

    st.push(node);
    return;
}

void topoLogicalSort(vector<int> adj[]) {
    int n = adj.size();

    vector<int> visited(n, 0);
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    while(!st.empty()) {
        cout << st.top;
        st.pop();
    }
    cout << endl;
}

int main() {
    return 0;
}