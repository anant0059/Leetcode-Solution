class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        map<int,int> trusts, trusted;
        for(auto i:trust){
            trusts[i[0]]++;
            trusted[i[1]]++;
        }
        for(auto i:trusted){
            if(i.second==n-1 && trusts[i.first]==0){
                return i.first;
            }
        }
        return -1;
    }
};