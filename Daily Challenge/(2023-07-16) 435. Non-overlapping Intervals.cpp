bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        int prev = INT_MIN;
        int n = intervals.size();
        for(int i = 0; i < n; ++i) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(prev <= x) {
                prev = y;
            }
            else {
                ++res;
            }
        }
        return res;
    }
};