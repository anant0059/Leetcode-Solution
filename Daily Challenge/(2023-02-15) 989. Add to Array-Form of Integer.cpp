class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry=0, n=num.size();
        for(int i=n-1;i>=0;--i){
            int tmp=k%10;
            k/=10;
            carry+=tmp+num[i];
            res.push_back(carry%10);
            carry/=10;
        }
        while(k){
            carry+=k%10;
            k/=10;
            res.push_back(carry%10);
            carry/=10;
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};