class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int index1 = 0, index2 = 0;
        string res = "";
        while(index1 < len1 && index2 < len2) {
            res += word1[index1];
            res += word2[index2];
            ++index1;
            ++index2;
        }
        if(index1 < len1) {
            res += word1.substr(index1);
        }
        if(index2 < len2) {
            res += word2.substr(index2);
        }
        return res;
    }
};