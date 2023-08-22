class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber) {
            int temp = columnNumber % 26;
            --columnNumber;
            columnNumber/=26;
            if(temp == 0) {
                temp = 26;
            }
            --temp;
            res = char('A' + temp) + res;
        }
        return res;
    }
};