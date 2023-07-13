class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> g(numCourses);

        for(auto i : prerequisites) {
            g[i[1]].push_back(i[0]);
            ++indegree[i[0]];
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while(q.size()) {
            int node = q.front();
            q.pop();
            ++visited;
            for(auto i : g[node]) {
                --indegree[i];
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        cout<<visited<<endl;

        return visited == numCourses;
    }
};