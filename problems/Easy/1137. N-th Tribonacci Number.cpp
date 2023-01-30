class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<3) return 1;
        int first=0,second=1,third=1,res=0,i=3;
        while(i<=n){
            res=first+second+third;
            first=second;
            second=third;
            third=res;
            ++i;
        }
        return res;
    }
};