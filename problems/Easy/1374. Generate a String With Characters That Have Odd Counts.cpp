class Solution {
public:
    string generateTheString(int n) {
        string res = "";
        if( n % 2 )
        {
            while( n-- )
            {
                res += 'a';
            }
        }
        else
        {
            res += 'a';
            --n;
            while( n-- )
            {
                res += 'b';
            }
        }
        return res;
    }
};