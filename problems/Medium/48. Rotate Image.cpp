class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),x=(n-1)/2;
        for(int i=0;i<=x;++i){
            for(int j=i;j<n-i-1;++j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};