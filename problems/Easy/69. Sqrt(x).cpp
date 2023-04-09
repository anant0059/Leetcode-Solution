class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 )
        {
            return 0;
        }
        long long int left = 0, right = x, mid;
        while( left <= right )
        {
            mid = ( left + right )/2;
            if( mid * mid == x )
            {
                return mid;
            }
            if( mid * mid > x )
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if( left * left > x ) return ( int ) ( left - 1 );
        return ( int ) left;
    }
};