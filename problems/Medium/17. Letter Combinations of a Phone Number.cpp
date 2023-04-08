class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> res,button;
        button={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        for(auto i:digits){
            vector<string> temp;
            for(auto j:button[i-'0']){
                for(auto k:res){
                    temp.push_back(k+j);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};