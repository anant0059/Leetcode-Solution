class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int first=0,second=1,res=0,i=2;
        while(i<=n){
            res=first+second;
            first=second;
            second=res;
            ++i;
        }
        return res;
    }
};