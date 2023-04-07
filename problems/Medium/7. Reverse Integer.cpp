class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN || x==INT_MAX) return 0;
        long long int ans=0,positive=1;
        if(x<0) x*=-1,positive=-1;
        
        while(x){
            ans*=10;
            ans+=x%10;
            x/=10;
        }
        ans*=positive;
        if(ans<INT_MIN || ans>INT_MAX) return 0;
        
        return ans;
    }
};