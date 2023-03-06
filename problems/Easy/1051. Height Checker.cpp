class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp=heights;
        sort(heights.begin(), heights.end());
        int res=0, n=heights.size();
        for(int i=0;i<n;++i){
            if(heights[i]!=tmp[i]){
                res++;
            }
        }
        return res;
    }
};