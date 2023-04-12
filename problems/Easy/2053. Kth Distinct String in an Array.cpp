class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map< string, int > mp;
        for( auto i : arr )
        {
            mp[i]++;
        }
        int kth = 0;
        for( auto i : arr )
        {
                if( mp[i] == 1 )
                {
                    ++kth;
                }
                if( kth == k )
                {
                    return i;
                }
        }
        return "";
    }
};