class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int res = 1;
        int i = 0;

        while( i < n )
        {
            vector< int > chars( 26, 0 );
            while( i < n )
            {
                if( chars[s[i]-'a'] > 0 )
                {
                    ++res;
                    break;
                }
                else
                {
                    chars[s[i]-'a']=1;
                }
                ++i;
            }
        }

        return res;
    }
};