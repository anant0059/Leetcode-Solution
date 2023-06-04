class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                queue<int> q;
                q.push(i);
                ++res;
                while(q.size()) {
                    int index = q.front();
                    q.pop();
                    if(!visited[index]) {
                        visited[index] = 1;
                        for(int j = 0; j < n; ++j) {
                            if(!visited[j]) {
                                if(isConnected[index][j]) {
                                    q.push(j);
                                    isConnected[index][j] = 0;
                                    isConnected[i][index] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};