class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int surplus=1,n=digits.size();
        vector<int> res;
        for(int i=n-1;i>=0;--i){
            surplus+=digits[i];
            res.insert(res.begin(),(surplus)%10);
            surplus/=10;
        }
        if(surplus) res.insert(res.begin(),surplus);
        return res;
    }
};