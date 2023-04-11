class Solution {
public:
    void f(int i,int j,int& n, vector<vector<string>> &res,vector<string> temp){
        //if(temp[i][j]=='.') return ;
        // temp[i][j]='.'
        // for(int k=j+1;k<n && temp[i][k]=='Q';++k) {
        //     if(temp[i][k]=='Q') f(i,k,n,res,temp);
        //     temp[i][k]='.';
        // }
        //temp[i][j]='Q';
        int ro=i+1,col=j+1;
        while(ro<n && col<n) temp[ro][col]='.',ro++,col++;
        ro=i+1,col=j-1;
        while(ro<n && col>=0) temp[ro][col]='.',ro++,col--;
        ro=i,col=j+1;
        while(col<n) temp[ro][col]='.',col++;
        col=j-1;
        while(col>=0) temp[ro][col]='.',col--;
        ro=i+1,col=j;
        while(ro<n) temp[ro][col]='.',ro++;
        if(i+1<n){
            for(int k=0;k<n;++k){
                if(temp[i+1][k]=='Q') f(i+1,k,n,res,temp),temp[i+1][k]='.';
            }
        }
        if(i==n-1) res.push_back(temp);
    }
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string>temp;
        string t="";
        for(int i=0;i<n;++i) t+='Q';
        for(int i=0;i<n;++i) temp.push_back(t);
        for(int i=0;i<n;++i) f(0,i,n,res,temp);
        return res.size();
    }
};