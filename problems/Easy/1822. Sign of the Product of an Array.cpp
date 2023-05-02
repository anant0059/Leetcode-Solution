class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size(), neg = 0;
        for(auto i : nums) {
            if( i == 0 ) {
                return 0;
            }
            if( i < 0 ) {
                ++neg;
            }
        }
        if( neg % 2 ) {
            return -1;
        }
        return 1;
    }
};