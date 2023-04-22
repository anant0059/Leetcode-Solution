class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
            if(matrix.empty()) return {};
            
            const int N = matrix.size();
            const int M = matrix[0].size();
            
            vector<int> res;
            for(int s = 0; s <= N + M - 2; ++s)
            {
                // for all i + j = s
                for(int x = 0; x <= s; ++x) 
                {
                    int i = x;
                    int j = s - i;
                    if(s % 2 == 0) swap(i, j);

                    if(i >= N || j >= M) continue;
                    
                    res.push_back(matrix[i][j]);
                }
            }
            
            return res;
        // int n = mat.size(), m = mat[0].size(), sz = n * m;
        // vector<int> res(sz, 0);
        // int row = 0, col =0;
        // int direction = 1, curr_sz = 0;
        // while(curr_sz < sz) {
        //     if( row < 0 ) {
        //         row = 0;
        //         direction = 0;
        //     }
        //     else if( col < 0 ) {
        //         col = 0;
        //         direction = 1;
        //     }
        //     if( col == m ) {
        //         col = m - 1;
        //     }
        //     else if( row == n ) {
        //         row = n - 1;
        //     }
        //     cout<< row<< " "<<col<<" "<<"difio"<<endl;
        //     res[curr_sz] = mat[row][col];
        //     if( direction == 0 ) {
        //         ++row;
        //         --col;
        //     }
        //     else {
        //         ++col;
        //         --row;
        //     }
        //     ++curr_sz;
        //     cout<< row<< " "<<col<<endl;
        // }
        // return res;
    }
};