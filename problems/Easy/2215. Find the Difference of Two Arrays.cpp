class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        map<int, int> mp1, mp2, mp3;
        for( auto i : nums1 ) {
            ++mp1[i];
        }
        for( auto i : nums2 ) {
            if(mp2[i] == 0 && mp1[i] == 0) {
                res[1].push_back(i);
            }
            ++mp2[i];
        }
        for( auto i : nums1 ) {
            if(mp3[i] == 0 && mp2[i] == 0) {
                res[0].push_back(i);
            }
            ++mp3[i];
        }
        return res;
    }
};