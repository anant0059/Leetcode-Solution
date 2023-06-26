class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int left = 0;
        int right = n - 1;
        long long res = 0;
        while(left < candidates && left < n) {
            pq.push({costs[left], left});
            ++left;
        }
        while(candidates && right >= left) {
            pq.push({costs[right], right});
            --right;
            --candidates;
        }

        while(k--) {
            int temp1 = pq.top().first, temp2 = pq.top().second;
            pq.pop();
            res += temp1;
            cout<<temp2<<endl;
            if(temp2<= left && right >= left) {
                pq.push({costs[left], left});
                ++left;
            }
            else if(temp2>= right && right >= left) {
                pq.push({costs[right], right});
                --right;
            }
        }
        return res;
    }
};