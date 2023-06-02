class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int n_bomb = 0;
            vector<int> visited(n, 0);
            
                queue<int> q;
                q.push(i);
                while(q.size()) {
                    int temp = q.front();
                    q.pop();
                    if(visited[temp] == 0) {
                        ++n_bomb;
                        cout<< temp<< " "<< n_bomb<<endl;
                        visited[temp] = 1;
                        for(int j = 0; j < n; ++j) {
                            if(visited[j] == 0) {
                                double dis = sqrt(pow(bombs[temp][0] - bombs[j][0], 2) + pow(bombs[temp][1] - bombs[j][1], 2));
                                if(dis <= bombs[temp][2]) {
                                    q.push(j);
                                }                          
                            }
                        }
                    }
                }
            
            res = max(res, n_bomb);
        }
        return res;
    }
};