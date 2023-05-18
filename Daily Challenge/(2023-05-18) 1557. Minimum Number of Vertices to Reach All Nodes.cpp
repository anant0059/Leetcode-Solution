class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int,int> to, from;
        for(auto i : edges) {
            ++to[i[1]];
        }
        vector<int> res;
        for(auto i : edges) {
            if(to[i[0]] == 0 && from[i[0]] == 0) {
                res.push_back(i[0]);
            }
            ++from[i[0]];
        }
        return res;
    }
};