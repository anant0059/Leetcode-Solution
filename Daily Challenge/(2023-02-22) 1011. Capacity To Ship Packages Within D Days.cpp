class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=0,n=weights.size();
        for(int i=0;i<n;++i) l=max(l,weights[i]), r+=weights[i];
        
        int mid=0,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            int count=0,tempsum=0;
            for(int i=0;i<n;++i){
                if(tempsum+weights[i]<=mid) tempsum+=weights[i];
                else count++,tempsum=weights[i];
            }
            count++; 
            
            if(count<=days) r=mid-1,ans=mid;
            else l=mid+1;
        }  
        return ans;
    }
};