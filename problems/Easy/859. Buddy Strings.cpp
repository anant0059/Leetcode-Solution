class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        map<char, int> mp;
        int n = s.size();
        int f = -1, f2 = 0;
        for(int i = 0; i < n; ++i) {
            mp[s[i]]++;
            if(s[i] != goal[i]) {
                if(f == -1) {
                    f = i;
                }
                else if(f == -2) {
                    return false;
                }
                else {
                    char temp = s[f];
                    s[f] = s[i];
                    s[i] = temp;
                    f = -2;
                }
            }
            if(mp[s[i]] > 1) {
                f2 = 1;
            }
        }
        if((f != -2 && f2 == 0) || s != goal) {
            return false;
        }
        return true;
    }
};