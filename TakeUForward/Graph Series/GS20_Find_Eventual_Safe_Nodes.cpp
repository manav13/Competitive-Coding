class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int> &visited, vector<int> &pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto adjNode : graph[node]) {
            if(!visited[adjNode]) {
                if(dfs(adjNode, graph, visited, pathVisited)) {
                    return true;
                }
            }
            else{
                if(pathVisited[adjNode]) {
                    return true;
                }
            }
        }

        pathVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, pathVisited);
            }
        }
        vector<int> safeNodes;

        for(int i=0; i<n; i++) {
            if(pathVisited[i] == 0) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};