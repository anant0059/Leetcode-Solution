class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> AL(n + 1);
        for (auto v : edges) {
            AL[v[0]].push_back(v[1]);
            AL[v[1]].push_back(v[0]);
        }
        int curr_time = 0, result = INT_MAX;
        vector<pair<int, int>> visited(n + 1, {0, 0});
        visited[1] = {0, 1};
        queue<int> BFSqueue;
        BFSqueue.push(1);
        while (!BFSqueue.empty()) {
            int waitTime =
                ((curr_time / change) & 1 ? change - (curr_time % change) : 0);
            curr_time += time + waitTime;
            int levelSize = BFSqueue.size();
            while (levelSize--) {
                int front = BFSqueue.front();
                BFSqueue.pop();
                for (int i : AL[front]) {
                    if (visited[i].first != curr_time) {
                        if (visited[i].second == 2)
                            continue;
                        visited[i].first = curr_time;
                        visited[i].second++;
                    }
                    if (i == n) {
                        if (result < curr_time)
                            return curr_time;
                        else
                            result = curr_time;
                    }
                    BFSqueue.push(i);
                }
            }
        }
        return -1;
    }
};