class Solution {
public:
    int search(vector<int>& nums, int target) {
        long long left=0,right=nums.size()-1,mid;
        while(left<right){
            mid=(left+right)/2;
            if(nums[(int)mid]>target){
                right=mid-1;
            }
            else if(nums[(int)mid]<target){
                left=mid+1;
            }
            else{
                return mid;
            }
        }
        if(nums[left]!=target) return -1;
        return (int)left;
    }
};