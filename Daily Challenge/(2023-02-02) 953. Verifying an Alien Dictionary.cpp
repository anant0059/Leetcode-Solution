class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        map<char,int> mp;
        for(int i=0;i<26;++i){
            mp[order[i]]=i+1;
        }
        for(int i=1;i<n;++i){
            int l1=words[i-1].size(),l2=words[i].size(),p1=0,p2=0,all_equal=1;
            while(p1<l1 && p2<l2){
                if(mp[words[i-1][p1]]>mp[words[i][p2]]){
                    //cout<<words[i-1][p1]<<" "<<words[i][p2]<<endl;
                    return false;
                }
                else if(mp[words[i-1][p1]]<mp[words[i][p2]]){
                    all_equal=0;
                    break;
                }
                ++p1;
                ++p2;
            }
            if(all_equal && l1>l2){
                return false;
            }
        }
        return true;
    }
};