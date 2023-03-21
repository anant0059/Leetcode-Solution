class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size(), i = 0, res = 0;
        while( i < n ){
            if( nums[i] == 0 ){
                long long tmp=i;
                while( i<n && nums[i] == 0 ){
                    ++i;
                }
                tmp = i - tmp;
                tmp = (tmp)*(tmp+1)/2;
                res += tmp;
            }
            else ++i;
        }
        return res;
    }
};