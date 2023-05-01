class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n = salary.size();
        double ans = 0;
        for(auto i : salary) {
            ans += (double) i;
        }
        ans -= salary[0];
        ans -= salary[n-1];
        return ans / (n-2);
    }
};