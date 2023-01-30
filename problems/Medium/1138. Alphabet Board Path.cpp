class Solution {
public:
    string alphabetBoardPath(string target) {
        map<char,pair<int,int>> mp;
        int first=0,second=0;
        for(char c='a';c<='z';++c){
            int tmp=c-'a';
            first=tmp/5;
            second=tmp-first*5;
            mp[c]={first,second};
        }
        string res="";
        first=0,second=0;
        for(auto c:target){
            int cfirst = mp[c].first;
            int csecond = mp[c].second;
            int l=0,r=0,d=0,u=0; 
            if(cfirst>first){
                d=cfirst-first;
            }
            else{
                u=first-cfirst;
            }
            if(csecond>second){
                r=csecond-second;
            }
            else{
                l=second-csecond;
            }
            for(int i=0;i<u;++i) res+='U';
            for(int i=0;i<r;++i) res+='R';
            for(int i=0;i<l;++i) res+='L';
            for(int i=0;i<d;++i) res+='D';
            res+='!';

            // cout<<first<<" "<<second<<endl;
            // cout<<cfirst<<" "<<csecond<<endl;
            first=cfirst;
            second=csecond;
        }
        return res;
    }
};