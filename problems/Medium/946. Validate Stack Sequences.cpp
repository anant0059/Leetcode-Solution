class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack < int > pushed_st;
        stack < int > popped_st;
        int n = pushed.size();
        int m = popped.size();
        int i = 0;
        int j = 0;
        while( i < n && j < m )
        {
            while( i < n && pushed[i] != popped[j])
            {
                pushed_st.push(pushed[i]);
                ++i;
            }
            while( i < n && j < m && pushed[i] == popped[j] )
            {
                ++i;
                ++j;
            }
            while( j < m && pushed_st.size() && pushed_st.top() == popped[j] )
            {
                pushed_st.pop();
                ++j;
            }
        }
        if( i == n && j == m && pushed_st.size() == 0 )
        {
            return true;
        }
        return false;
    }
};