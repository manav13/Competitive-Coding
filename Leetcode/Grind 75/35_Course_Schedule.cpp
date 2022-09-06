#include<bits/stdc++.h>
using namespace std;

bool dfs(int course, vector<bool> &isVisited, unordered_map<int, vector<int>> &preHash) {
    if(isVisited[course])
        return false;
    
    isVisited[course] = true;
    int size = preHash.size();
    for(auto c : preHash[course]) {
        if(!dfs(c, isVisited, preHash))
            return false;
    }
    isVisited[course] = false;
    preHash[course] = {};
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> preHash;
    for(int i=0; i<numCourses; i++) {
        preHash[i] = {};
    }
    for(auto pre : prerequisites) {
        preHash[pre[0]].push_back(pre[1]);
    }
    vector<bool> isVisited(numCourses, false);
    for(auto courses : preHash) {
        if(!dfs(courses.first, isVisited, preHash))
            return false;
    }
    return true;
}

int main() {
    int numCourses = 5;
    vector<vector<int>> prerequisites = {
        {1,4}, {2,4}, {3,1}, {3,2}
    };
    cout << canFinish(numCourses, prerequisites) << endl;
    return 0;
}