class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n=time.size(),sm=INT_MAX;
        for(int i=0;i<n;++i){
            if(sm>time[i]) sm=time[i];
        }
        long long frst=1,last=sm*totalTrips,mid,ans=0;
        while(frst<last){
            mid=(frst+last)/2;
            ans=0;
            for(int i=0;i<n;++i){
                ans+=mid/time[i];
            }
            //cout<<mid<<ans<<endl;
            //if(ans==totalTrips) return mid;
            if(ans<totalTrips) frst=mid+1;
            else last=mid;
        }
        return frst;
    }
};