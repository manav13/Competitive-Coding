class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);

        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> courseOrder;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            courseOrder.push_back(course);

            for(auto pre : graph[course]) {
                indegree[pre]--;
                if(indegree[pre] == 0) {
                    q.push(pre);
                }
            }
        }

        if(courseOrder.size() != numCourses)
            return {};

        return courseOrder;
    }
};