class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        int count = 0, carry = 0;
        for(int i=0; i<n; ++i) {
            res[i] += carry;
            if(boxes[i] == '1') {
                ++count;
            }
            carry += count;
        }count = 0, carry = 0;
        for(int i=n-1; i>=0; --i) {
            res[i] += carry;
            if(boxes[i] == '1') {
                ++count;
            }
            carry += count;
        }
        return res;
    }
};