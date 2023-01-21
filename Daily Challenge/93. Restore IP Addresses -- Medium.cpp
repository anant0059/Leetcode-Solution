class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        if(n>12 || (n==12 && s[0]>'2')) return {};
        vector<string> res;
        queue<pair<string,pair<string, int>>> q;
        string st="";
        st+=s[0];
        q.push({st,{st, 0}});
        q.push({st+'.',{"",1}});
        for(int i=1;i<n;++i){
            int len=q.size();
            for(int j=0;j<len;++j){
                pair<string,pair<string, int>> temp=q.front();
                q.pop();
                if(temp.second.second>3) continue;
                if(temp.second.first.size()==0) {
                    q.push({temp.first+s[i],{temp.second.first+s[i],temp.second.second}});
                    q.push({temp.first+s[i]+".",{"",temp.second.second+1}});
                }
                else{
                    int t=stoi(temp.second.first);
                    if(temp.second.first[0]=='0' && t>0) continue;
                    else if(t>255) continue;
                    else {
                        q.push({temp.first+s[i],{temp.second.first+s[i],temp.second.second}});
                        q.push({temp.first+s[i]+".",{"",temp.second.second+1}});
                    }
                }
            }
            len=q.size();
            if(i==n-1){
                while(len--){
                    string tmp=q.front().first;
                    int t=q.front().second.second;
                    q.pop();
                    if(t!=3 || tmp[tmp.size()-1]=='.'){
                        continue;
                    }
                    int l=tmp.size(),idx=0,flag=1;
                    while(idx<l){
                        string x="";
                        while(idx<l && tmp[idx]!='.'){
                            x+=tmp[idx];
                            idx++;
                        }
                        if(stoi(x)>255 || (x[0]=='0' && stoi(x)>0) || (x[0]=='0' && x.size()>1)) flag=0;
                        idx++;
                    }
                    if(flag){
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};