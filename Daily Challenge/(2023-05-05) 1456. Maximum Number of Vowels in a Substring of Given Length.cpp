class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int res = 0;
        int current_vowels = 0;
        for(int i = 0; i < k; ++i) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++current_vowels;
            }
        }
        res = current_vowels;
        // cout<< res <<endl;
        int left = 0, right = k;
        while(right < n) {
            if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') {
                --current_vowels;
            }
            if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
                ++current_vowels;
            }
            //cout<<s[left]<<" "<<s[right]<<endl;
            ++left;
            ++right;
            res = max(res, current_vowels);
            // cout<<res<<endl;
        }
        return res;
    }
};