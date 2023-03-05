class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> graph;
        int n=arr.size();
        for(int i=0;i<n;++i){
            graph[arr[i]].push_back(i);
            //cout<<graph[arr[i]].size()<<endl;
        }
        cout<<graph[7].size()<<endl;
        //return arr.size();
        
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<int> visited(n,n);
        visited[0]=0;
        map<int,int> mp;
        while(q.size()){
            int node=q.front().first, val=q.front().second;
            //cout<<node<<" "<<val<<" "<<"cc";
            q.pop();
            if(node==n-1) return val;
            if(node-1>=0 && visited[node-1]>val+1){
                q.push({node-1,val+1});
                visited[node-1]=val+1;
            }
            if(node+1<n && visited[node+1]>val+1){
                q.push({node+1,val+1});
                visited[node+1]=val+1;
            }
            if(mp[arr[node]]==0){
                for(auto x:graph[arr[node]]){
                    //cout<<node <<x<<" "<<graph[node].size();
                    if(visited[x]>val+1 && node!=x){
                        q.push({x,val+1});
                        visited[x]=val+1;
                    }
                }
                mp[arr[node]]++;
            }
            //cout<<endl;
        }
        return 0;
    }
};