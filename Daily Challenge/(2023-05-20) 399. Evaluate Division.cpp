class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
         unordered_map<string,vector<pair<string,double>>> eq;
        for(int i=0;i<n;++i){
            eq[equations[i][0]].push_back({equations[i][1],values[i]});
            eq[equations[i][1]].push_back({equations[i][0],(1/values[i])});
        }
        vector<double> res;
        for(auto i:queries){
            if(i[0]==i[1] && eq[i[0]].size()){
                res.push_back(1);
                continue;
            }
            bool flag=0;
            queue<pair<string,double>> q;
            q.push({i[0],1});
            map<string,int> mp;
            while(q.size()){
                string next=q.front().first;
                double temp=q.front().second;
                q.pop();
                if(mp[next]) continue;
                mp[next]=1;
                for(auto j: eq[next]){
                    if(mp[j.first]) continue;
                    q.push({j.first,temp*j.second});
                    if(j.first==i[1]){
                        res.push_back(temp*j.second);
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
            }
            if(flag==0) res.push_back(-1);        
        }
        return res;
    }
};