class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),left=0,right=n-1,mid;
        if(n==0) return {-1,-1};
        
        int lower_bound,upper_bound;
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]<target) left= mid+1;
            else right=mid;
        }
        
        lower_bound=left;
        if(nums[lower_bound]!=target) return {-1,-1};
        
        left=0,right=n;
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]<=target) left= mid+1;
            else right=mid;
        }
        upper_bound=left;
            
        return {lower_bound,upper_bound-1};
        
    }
};