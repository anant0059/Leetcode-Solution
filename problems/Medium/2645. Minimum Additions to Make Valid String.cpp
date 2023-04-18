class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int ans = 0;
        char prev = 'a';
        if(n == 0) {
            return 3;
        }
        if(word[0] == 'b') {
            prev = 'b';
            ans++;
        }
        else if(word[0] == 'c') {
            prev = 'c';
            ans += 2;
        }
        for(int i=1; i<n; ++i) {
            if(word[i] == 'a') {
                if(prev == 'a') {
                    ans += 2;
                }
                else if(prev == 'b') {
                    ans++;
                }
            }
            else if(word[i] == 'b') {
                if(prev == 'b') {
                    ans += 2;
                }
                else if(prev == 'c') {
                    ans++;
                }
            }
            else {
                if(prev == 'c') {
                    ans += 2;
                }
                else if(prev == 'a') {
                    ans++;
                }
            }
            prev = word[i];
        }
        if(word[n-1] == 'b') {
            ans++;
        }
        else if(word[n-1] == 'a') {
            ans += 2;
        }
        return ans;
    }
};