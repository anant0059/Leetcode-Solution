class Solution {
public:
        int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (test(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    long test(int n, int index, int a) {
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return res - a;
    }

    
    // int maxValue(int n, int index, int maxSum) {
    //     if(maxSum == n) {
    //         return 1;
    //     }
    //     int res = 2, x = 1, xx = n - 1 - index;
    //     long long sm = n + 1, prev = (min(x , index) + min(x , xx) + 1);
    //     while(sm +  prev <= maxSum) {
    //         sm += prev;
    //         ++res;
    //         ++x;
    //         prev = (min(x , index) + min(x , xx) + 1);
    //     }
    //     return (int)res;
    // }
};