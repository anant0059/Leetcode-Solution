class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size(),m=str2.size(),sz=min(n,m);
        string res="",s="";
        for(int i=0;i<sz;++i){
            s+=str1[i];
            if(n%(i+1)==0 && m%(i+1)==0){
                //cout<<i<<endl;
                bool flag1=1,flag2=1;
                int p1=0,p2=0;
                while(p2<n){
                    if(p1%(i+1)==0) p1=0;
                    if(str1[p2]!=s[p1]){
                        flag1=0;
                        break;
                    }
                    //cout<<str1[p2]<<" "<<s[p1]<<endl;
                    p1++;
                    p2++;
                }
                p1=0,p2=0;
                while(p2<m){
                    if(p1%(i+1)==0) p1=0;
                    if(str2[p2]!=s[p1]){
                        flag2=0;
                        break;
                    }
                    p2++;
                    p1++;
                }
                if(flag1 && flag2 && s.size()>res.size()){
                    res=s;
                }
            }
        }
        return res;
    }
};