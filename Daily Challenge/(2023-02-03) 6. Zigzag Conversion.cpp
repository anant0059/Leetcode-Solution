class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> v;
        for(int i=0;i<numRows;++i){
            v.push_back("");
        } 
        int n=s.size(),currow=0,pattern=0;
        string res="";
        for(int i=0;i<n;++i){
            if(currow==numRows){
                pattern=1;
                currow=numRows-2;
            }
            if(currow<=0){
                pattern=0;
            }
            cout<<v[currow]<<" "<<currow<<endl;
            v[currow]+=s[i];
            if(pattern==0) currow++;
            if(pattern==1) currow--;
        }
        for(auto i:v) res+=i;
        return res;
    }
};