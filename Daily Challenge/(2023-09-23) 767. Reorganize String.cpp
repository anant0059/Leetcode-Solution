class Solution {
public:
    string reorganizeString(string s) {
        vector<int> v(26, 0);
        int mx = 0;
        for(auto i : s) {
            ++v[i-'a'];
            if(v[mx] < v[i-'a']) {
                mx = i-'a';
            }
        }

        cout<<mx<<endl;

        if(v[mx] * 2 - 1 > s.size()) {
            return "";
        }

        int n = s.size();
        int i = 0;
        while(v[mx]) {
            s[i] = char('a' + mx);
            i += 2;
            --v[mx];
        }

        cout<<v[mx]<<endl;

        for(int j = 0; j < 26; ++j) {
            while(v[j]) {
                if(i >= n) {
                    i = 1;
                }
                s[i] = char('a' + j);
                --v[j];
                i += 2;
            }
        }

        return s;
    }
};