// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=0,right=n,mid;
        while(left<right){
            mid=(left+right)/2;
            if(isBadVersion((int)mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return (int)left;
    }
};