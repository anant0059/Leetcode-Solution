class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, n=nums.size();
        for(int j=0;j<n;){
            int tmp=j;
            while(tmp<n && nums[j]==nums[tmp]) tmp++;
            nums[i]=nums[j];
            i++;
            if(tmp-j>1) nums[i]=nums[j],i++;
            j=tmp;
        }
        return i;
    }
};