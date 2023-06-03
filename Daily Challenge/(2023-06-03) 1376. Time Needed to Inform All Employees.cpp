class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int mx=0;
        vector<int> v(n,0);
        for(int i=0;i<n;++i){
            if(manager[i]==-1) continue;
            int temp=i,h=0;
            while(manager[temp]!=-1){
                h+=informTime[manager[temp]];
                temp=manager[temp];
            }
            v[i]=h+v[temp];
            mx=max(mx,v[i]);
            manager[i]=-1;
        }
        return mx;
    }
};