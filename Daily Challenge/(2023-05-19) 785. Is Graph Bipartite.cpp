class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int visted[n];
        for(int i=0;i<n;++i){
            visted[i]=0;
        }
        for(int i=0;i<n;++i){
            if(visted[i]==0){
                queue<int> q;
                q.push(i);
                visted[i]=-1;
                while(!q.empty()){
                    int node=q.front(),colour=visted[node];
                    q.pop();
                    for(auto i:graph[node]){
                        if(visted[i]==0){
                            if(colour==-1) visted[i]=1;
                            else visted[i]=-1;
                            q.push(i);
                        }
                        else if(visted[i]==colour) return false;
                    }
                }
            }
        }
        return true;
    }
};