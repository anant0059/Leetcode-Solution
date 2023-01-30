class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size(),first=newInterval[0],last=newInterval[1],flag=0;
        for(auto i:intervals){
            if(i[1]<first) res.push_back(i);
            else if(i[1]<=last or i[0]<=last) first=min(first,i[0]),last=max(last,i[1]);
            else if(flag==0) res.push_back({first,last}),res.push_back(i),flag=1;
            else res.push_back(i);
        }
        if(flag==0) res.push_back({first,last});
        return res;
    }
};