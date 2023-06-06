class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int prev = arr[1];
        int diff = arr[1] - arr[0];
        for(int i = 2; i < n; ++i) {
            if(diff != arr[i] - prev) {
                return false;
            }
            prev = arr[i];
        }
        return true;
    }
};