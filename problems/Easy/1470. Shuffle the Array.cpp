class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        n*=2;
        vector<int> res(n);
        int left=0,right=(n/2),i=0;
        while(right<n){
            res[i++]=nums[left++];
            res[i++]=nums[right++];
        }
        return res;
    }
};