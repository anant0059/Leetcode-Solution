class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for (auto i : candies)
        {
            mx = max(mx, i);
        }
        int n = candies.size();
        vector< bool > res(n, false);
        for (int i=0;i<n;++i)
        {
            if(candies[i] + extraCandies >= mx)
            {
                res[i] = true;
            }
        }
        return res;
    }
};