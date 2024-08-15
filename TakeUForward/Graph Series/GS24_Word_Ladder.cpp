#include<bits/stdc++.h>
using namespace std;

// Code is BUGGY, does not give correct output

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

bool canTransform(string word1, string word2) {
    // unordered_map<char, int> hash;

    // for(auto c : word1) {
    //     hash[c]++;
    // }
    // for(auto c : word2) {
    //     hash[c]--;
    // }

    // int countOnes = 0;
    // int countMinusOnes = 0;

    // for(auto it : hash) {
    //     if(it.second == 1)
    //         countOnes++;
    //     if(it.second == -1)
    //         countMinusOnes++;
    // }
    // return (countOnes == 1 && countMinusOnes == 1);

    int countDifferentChar = 0;
    int size = word1.size();
    for(int i=0; i<size; i++) {
        if(word1[i] != word2[i]) {
            countDifferentChar++;
        }
        if(countDifferentChar > 1)
            return false;
    }
    return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // {word, index}
    bool isBeginWordIncluded = false;
    for(auto word : wordList) {
        if(beginWord == word) {
            isBeginWordIncluded = true;
            break;
        }
    }
    if(!isBeginWordIncluded)
        wordList.insert(wordList.begin(), beginWord);
    map<string, int> hash;
    int count = 0;
    for(auto word : wordList) {
        hash[word] = count;
        count++;
    }

    if(hash.find(endWord) == hash.end()) {
        return 0;
    }

    int n = hash.size();
    // Create a graph using index
    vector<int> graph[n];

    for(int i=0; i<n; i++) {
        
        string word1 = wordList[i];
        int u = hash[word1];
        
        for(int j=i+1; j<n; j++) {
            string word2 = wordList[j];
            int v = hash[word2];

            if(canTransform(word1, word2)) {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }

    vector<int> dist = shortestPath(0, n, graph);
    if(dist[hash[endWord]] == 1e9)
        return 0;
    return dist[hash[endWord]];
}

int main() {

    string beginWord = "leet";
    string endWord = "code";

    vector<string> wordList = {"lest","leet","lose","code","lode","robe","lost"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}