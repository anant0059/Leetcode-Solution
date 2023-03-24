class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_map<int,int>> paths;
        unordered_map<int, vector<int>> graph;
        for(auto path: connections){
            paths[path[0]][path[1]]=1;
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }

        int res = 0;
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        while(q.size()){
            int node=q.front();
            q.pop();
            if(visited[node]) continue;
            visited[node]=1;
            for(auto i:graph[node]){
                if(visited[i]==0){
                    if(paths[node][i]==1) res++;
                    q.push(i);
                }
            }
        }
        return res;
    }
};