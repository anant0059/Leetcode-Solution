class Solution {
public:
   bool isvalid(vector<vector<char>>& board,int row,int col,char c)    {
        c=board[row][col];
        board[row][col]='.';
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(!isvalid(board,i,j,board[i][j])){
                    return false;
                }
                
            }
        }
        return true;
    }
};