class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;++i){
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int i=0;
        priority_queue<int> pq;
        while(k--){
            while(i<n && v[i].first<=w) {
                pq.push(v[i].second);
                ++i;
            }
            if(pq.size()==0){
                break;
            }
            //cout<<pq.size()<<endl;
            w+=pq.top();
            pq.pop();
            //cout<<w<<endl;
        }
        return w;
    }
};