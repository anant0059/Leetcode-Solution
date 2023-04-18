class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int mx = 0;
        for(int i=0; i<n; ++i) {
            int temp = 0;
            for(int j=0; j<m; ++j) {
                if(mat[i][j] == 1) {
                    ++temp;
                }
            }
            mx = max(mx, temp);
        }
        for(int i=0; i<n; ++i) {
            int temp = 0;
            for(int j=0; j<m; ++j) {
                if(mat[i][j] == 1) {
                    ++temp;
                }
            }
            if(temp == mx) {
                return {i, mx};
            }
        }
        return {0, mx};
    }
};