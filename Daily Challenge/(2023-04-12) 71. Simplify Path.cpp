class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack< string > st;
        int index = 0;
        while( index < n ){
            if( path[index] == '/' )
            {
                ++index;
                continue;
            }
            string temp = "";
            while( index < n && path[index] != '/' )
            {
                temp += path[index];
                ++index;
            }
            ++index;
            if( temp == "." )
            {
                continue;
            }
            else if( temp == ".." )
            {
                if( st.size() )
                {
                    st.pop();
                }
            }
            else
            {
                st.push( temp );
            }
        }
        string res = "";
        while( st.size() )
        {
            res = "/" + st.top() + res;
            // cout<< st.top() << endl;
            st.pop();
        }
        if( res.size() == 0 )
        {
            return "/";
        }
        return res;
    }
};