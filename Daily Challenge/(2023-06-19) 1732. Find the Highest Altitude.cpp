class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0, sm = 0;
        for(auto i : gain) {
            sm += i;
            mx = max(mx, sm);
        }
        return mx;
    }
};