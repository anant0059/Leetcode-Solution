class Solution {
public:
    bool isNumber(string s) {
        int n=s.size(),i=0,dot=0,dig=0;
        while(i<n && s[i]==' ') ++i;
        if(i<n && (s[i]=='+' || s[i]=='-')) ++i;
        while(i<n && ((s[i]>='0' && s[i]<='9') || s[i]=='.')){
            if(s[i]=='.') dot++;
            else dig++;
            ++i;
        }
        //cout<<i<<endl;    
        if(dig==0 || dot>1) return 0;
        if(i<n  && (s[i]=='e' || s[i]=='E')){
            i++;
            if(i<n && (s[i]=='-' || s[i]=='+')) ++i;
            dot=0,dig=0;
            while(i<n && ((s[i]>='0' && s[i]<='9') || s[i]=='.')){
                if(s[i]=='.') dot++;
                else dig++;
                ++i;
            }
            if(dig==0 || dot>0) return 0;      
        }
        if(i<n) return 0;
        return 1;
    }
};