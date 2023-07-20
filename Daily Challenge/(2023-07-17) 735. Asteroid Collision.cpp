class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        for(auto i: asteroids){
            int flag=0;
            while(i<0 && st.size() && st.top()>0 && abs(i)>=st.top() ){
                if(st.top()==abs(i)) {
                    st.pop();
                    flag=1;
                    break;
                }
                st.pop();
            }
            if(i>0) st.push(i);
            else if(flag==0 && (st.empty() or st.top()<0)) st.push(i);
        }
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};