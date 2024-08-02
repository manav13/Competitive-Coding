class Solution {
public:

    bool bfs(int i, vector<vector<int>>& graph, vector<int> &visited) {
        queue<int> q;
        q.push(i);
        visited[i] = 0;

        while(!q.empty()) {
            int node = q.front();
            int color = visited[node];
            q.pop();

            // Iterate through adjacent nodes
            for(auto v : graph[node]) {
                if(visited[v] == -1) {
                    q.push(v);
                    visited[v] = (color == 0) ? 1 : 0;
                }
                else {
                    if(visited[v] == color)
                        return false;
                }
            }
        }

        return true;
    }

    bool dfs(int i, int color, vector<vector<int>>& graph, vector<int> &visited) {
        visited[i] = color;

        for(auto node : graph[i]) {
            if(visited[node] == -1) {
                visited[node] = (color == 0) ? 1 : 0;
                if(dfs(node, visited[node], graph, visited) == false)
                    return false;
            }
            else {
                if(visited[node] == color)
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        
        for(int i=0; i<n; i++) {
            if(visited[i] == -1) {
                // if(!bfs(i, graph, visited)) {
                //     return false;
                // }
                if(!dfs(i, 0, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};