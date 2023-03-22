class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int,int>> g;
        int res=INT_MAX;
        for(auto i: roads){
            g[i[0]][i[1]]=i[2];
            g[i[1]][i[0]]=i[2];
        }
        vector<int> visited(n,0);
        queue<int> q;
        //q.push(0);
        for(int i=0;i<=0;++i){
            if(visited[i]==0) {
                q.push(i+1);
                int tempres=INT_MAX;
                while(q.size()){
                    int node=q.front();
                    q.pop();
                    visited[node-1]=1;
                    for(auto child:g[node]){
                        tempres=min(tempres, child.second);
                        if(visited[child.first-1]==0) q.push(child.first);
                    }
                }
                res=min(res, tempres);
            }
        }
        return res;
        // int res=roads[0][2];
        // for(auto i:roads) res=min(res, i[2]);
        // return res;
    }
};