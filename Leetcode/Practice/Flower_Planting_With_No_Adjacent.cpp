#include<bits/stdc++.h>
using namespace std;

bool isPossible(int col, int node, vector<vector<int>> graph, vector<int> colors) {
    for(int i=0; i<colors.size(); i++) {
        if(i!=node && graph[node][i] == 1 && colors[i]==col) 
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>> graph, vector<int> &colors) {
    if(node == colors.size()) {
        return true;
    }
    for(int col=1; col<=4; col++) {
        if(isPossible(col, node, graph, colors)) {
            colors[node] = col;
            if(solve(node+1, graph, colors)) 
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    // Create graph using adjacency matrix
    vector<vector<int>> graph(n, vector<int> (n, 0));
    for(auto pair : paths) {
        graph[pair[0]-1][pair[1]-1] = 1;
        graph[pair[1]-1][pair[0]-1] = 1;
    }
    vector<int> colors(n, 0);
    solve(0, graph, colors);
    return colors;
}

int main() {
    vector<vector<int>> paths = {
        {1, 2},
        {2, 3},
        {3, 1}
    };
    int n = 3;
    vector<int> colors = gardenNoAdj(n, paths);
    for(auto c : colors) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}