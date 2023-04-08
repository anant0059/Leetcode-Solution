class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            double temp;
            if((nums[mid] < nums[0]) == (target < nums[0])) {
                temp=nums[mid];
            }
            else if(target < nums[0]){
                temp=-INFINITY;
            }
            else {
                temp=INFINITY;
            }

            if (temp < target)
                lo = mid + 1;
            else if (temp > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};