class Solution {
public:

    void bfs(int node, vector<vector<int>>& isConnected, vector<int> &visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        int n = isConnected.size();

        while(!q.empty()) {
            int vertex = q.front();
            q.pop();

            // Iterate through neighbours
            for(int i=0; i<n; i++) {
                if(!visited[i] && isConnected[vertex][i] == 1) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        } 
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProvinces = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                numOfProvinces++;
                bfs(i, isConnected, visited);
            }
        }

        return numOfProvinces;
    }
};