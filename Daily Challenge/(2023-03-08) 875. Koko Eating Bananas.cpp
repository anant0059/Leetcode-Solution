class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=piles.size(), l=1,r=0;
        for(auto bananas: piles) r=max(r,bananas);
        
        int mid=0, ans=0;
        while(l<=r){
            mid=(l+r)/2;
            long long int count=0;
            for(auto bananas: piles){
                count+=bananas/mid;
                if(bananas%mid) count++;
            }
            if(count<=h) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};