class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(auto i: flights){
            graph[i[0]].push_back({i[1],i[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,0});

        vector<int> dist(n+1, INT_MAX);
        while(pq.size()){
            vector<int> temp=pq.top();
            pq.pop();
            if(temp[1]==dst){
                return temp[0];
            }
            if(dist[temp[1]]<temp[2]) continue;
            dist[temp[1]]=temp[2];
            if(temp[2]<=k){
                for(auto i:graph[temp[1]]){
                    pq.push({temp[0]+i.second, i.first, temp[2]+1});
                }
            }
        }

        return -1;


        // vector<int> visited(n,0);
        // vector<vector<pair<int,int>>> g(n);
        // for(auto i:flights){
        //     g[i[0]].push_back({i[1],i[2]});
        // }
        // queue<vector<int>> q;
        // q.push({src,0,0});
        // int ans=INT_MAX;
        // while(q.size()){
        //     int l=q.size();
        //     while(l--){
        //         vector<int> tmp=q.front();
        //         //cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
        //         q.pop();
        //         if(visited[tmp[0]] || tmp[2]>k+1){
        //             continue;
        //         }
        //         if(tmp[0]==dst){
        //             //cout<<"ioddsjf"<<endl;
        //             ans=min(ans,tmp[1]);
        //             continue;
        //         }
        //         for(auto i:g[tmp[0]]){
        //             q.push({i.first, tmp[1]+i.second, tmp[2]+1});
        //         }
        //         visited[tmp[0]]=1;
        //     }
        // }
        // if(ans==INT_MAX) return -1;
        // return ans;
    }
};