class Solution {
public:
    bool IsPalindrome(string s){
        int len=s.size(),i=0,j=len-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n=s.size(),i=1;
        vector<vector<string>> res;
        queue<vector<string>> q;
        string ss="";
        ss+=s[0];
        q.push({ss});
        while(i<n){
            int len=q.size();
            while(len--){
                vector<string> tmp=q.front();
                q.pop();
                if(IsPalindrome(tmp[tmp.size()-1])){
                    vector<string> temp=tmp;
                    string t="";
                    t+=s[i];
                    temp.push_back(t);
                    q.push(temp);
                }
                tmp[tmp.size()-1].push_back(s[i]);
                q.push(tmp);
            }
            ++i;
        }
        while(q.size()){
            if(IsPalindrome(q.front()[q.front().size()-1])) res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};