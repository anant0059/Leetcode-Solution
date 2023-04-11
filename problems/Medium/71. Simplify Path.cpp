class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n=path.size();
        for(int i=0;i<n;){
            string temp="";
            if(path[i]=='/') {
                i++;
                continue;
            }
            while(i<n && path[i]!='/') temp+=path[i],++i;
            if(temp==".") continue;
            if(temp=="..") {
                if(s.size()) s.pop();
                continue;
            }
            //cout<<temp<<endl;
            s.push(temp);
        }
        string res="";
        while(s.size()){
            res="/"+s.top()+res;
            s.pop();
        }
        if(res.size()==0) return "/";
        return res;
    }
};