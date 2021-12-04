#include<bits/stdc++.h>
using namespace std;

void DFS(int **edges, int n, int index, bool *visited) {
    cout << index << endl;
    visited[index] = true;
    for(int i=0; i<n; i++) {
        if(i == index) continue;
        if(edges[index][i] == 1) {
            if(visited[i] == 1) continue;
            DFS(edges, n, i, visited);
        }
    }
}

void BFS(int **edges, int n, int index) {
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
    queue<int> queue;
    queue.push(index);
    visited[index] = true;

    while(!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        cout << currentVertex << endl;
        for(int i=0; i<n; i++) {
            if(index == i) continue;
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                queue.push(i);
                visited[i] = true;
            } 
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    bool *visited = new bool[n];
    int **edges = new int* [n];
    for(int i=0; i<n; i++) {
        edges[i] = new int[e];
        visited[i] = false;
        for(int j=0; j<e; j++) {
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << "DFS: " << endl;
    DFS(edges, n, 0, visited);

    cout << "BFS: " << endl;
    BFS(edges, n, 0);
}