class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a || b || c) {
            if(c%2) {
                if(a%2 == 0 && b%2 == 0) {
                    ++res;
                }
            }
            else {
                if((a%2 && b%2 == 0) || (a%2 == 0 && b%2)) {
                    ++res;
                }
                else if(a%2 && b%2) {
                    res += 2;
                }
            }
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return res;
    }
};