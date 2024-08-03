// Topological sort to detect a cycle in the graph
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);

            indegree[pre[0]]++;
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int pendingCourses = numCourses;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            pendingCourses--;

            for(auto preCourse : adj[course]) {
                indegree[preCourse]--;
                if(indegree[preCourse] == 0) {
                    q.push(preCourse);
                }
            }
        }
        return pendingCourses == 0;
    }
};