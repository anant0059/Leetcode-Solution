class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        map<vector<int>, int> mp;
        for(auto i : grid) {
            ++mp[i];
        }
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < n; ++j) {
                temp.push_back(grid[j][i]);
            }
            res += mp[temp];
        }
        return res;
    }
};