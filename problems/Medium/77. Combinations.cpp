class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({});
        for(int i=1;i<=n;++i){
            int n=q.size();
            while(n--){
                if(q.front().size()==k) res.push_back(q.front()), q.pop();
                else{
                    q.push(q.front());
                    q.front().push_back(i);
                    if(q.front().size()==k) res.push_back(q.front()), q.pop();
                    else q.push(q.front()),q.pop();
                }
            }
        }
        return res;
    }
};