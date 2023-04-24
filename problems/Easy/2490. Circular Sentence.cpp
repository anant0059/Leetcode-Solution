class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence == "") {
            return true;
        }
        int n = sentence.size();
        if(sentence[0] != sentence[n-1]) {
            return false;
        }
        int space = 0;
        char c = sentence[0];
        for(int i=0; i<n; ++i) {
            if(space == 1 && c != sentence[i]) {
                return false;
            }
            if(sentence[i] != ' ') {
                c = sentence[i];
                space = 0;
            }
            else {
                space = 1;
            }
        }
        return true;
    }
};