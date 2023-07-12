class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i) {
            for(auto node : graph[i]) {
                ++indegree[i];
                adj[node].push_back(i);
            }
        }

        vector<bool> safe(n);
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(q.size()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for(auto i : adj[node]) {
                --indegree[i];
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if(safe[i]) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};