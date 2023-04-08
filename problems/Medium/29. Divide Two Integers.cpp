class Solution {
public:
    int divide(int dividend, int divisor) {
        long long div=divisor, divi=dividend;
        long long res=divi/div;
        //cout<<res<<endl;
        if(res>INT_MAX) return INT_MAX;
        return int(res);
    }
};