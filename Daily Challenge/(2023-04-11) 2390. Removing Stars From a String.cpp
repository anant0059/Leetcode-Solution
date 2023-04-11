class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string res="";
        for(auto i:s){
            if(i=='*') st.pop();
            else st.push(i);
        }
        while(st.size()) res+=st.top(), st.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};