class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size();
        int i = 0, j = 0;
        while( i < n && j < n ) {
            res += mat[i][j];
            ++i;
            ++j;
        }
        i = 0;
        j = n-1;
        while( i < n && j > -1 ) {
            res += mat[i][j];
            ++i;
            --j;
        }
        if( n % 2 ) {
            int tmp = n/2;
            res -= mat[tmp][tmp];
        }
        return res;
    }
};