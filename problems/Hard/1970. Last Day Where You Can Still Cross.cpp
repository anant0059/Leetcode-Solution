class Solution {
public:
    bool ifpossible(int &row, int &col, int mid, vector<vector<int>> &cells) {
        vector<vector<int>> matrix(row, vector<int> (col, 0));
        for(int i = 0; i < mid; ++i) {
            matrix[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        for(int i = 0; i < col; ++i) {
            if(matrix[0][i] == 0) {
                queue<pair<int,int>> q;
                q.push({0, i});
                while(q.size()) {
                    int x = q.front().first, y = q.front().second;
                    if(x == row - 1) {
                        return true;
                    }
                    q.pop();
                    if(matrix[x][y]) {
                        continue;
                    }
                    matrix[x][y] = 1;
                    if(x - 1 >= 0 && matrix[x - 1][y] == 0) {
                        q.push({x-1, y});
                    }
                    if(x + 1 < row && matrix[x + 1][y] == 0) {
                        q.push({x+1, y});
                    }
                    if(y - 1 >= 0 && matrix[x][y-1] == 0) {
                        q.push({x, y-1});
                    }
                    if(y + 1 < col && matrix[x][y+1] == 0) {
                        q.push({x, y+1});
                    }
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row * col, res = 0;
        while(left < right) {
            int mid = (left + right) / 2;
            if(ifpossible(row, col, mid, cells)) {
                left = mid + 1;
                res = mid;
            }
            else {
                right = mid;
            }
        }
        return res;
    }
};