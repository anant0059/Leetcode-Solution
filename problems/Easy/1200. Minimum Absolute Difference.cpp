class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int df = INT_MAX;
        for(int i=1; i<n; i++){
           df = min(df, abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>>ans;
        if(n ==2){ans.push_back({arr[0], arr[1]});
        return ans;}
        for(int i=1; i<n; i++){
            if(df ==  arr[i]-arr[i-1]){
                ans.push_back({arr[i-1], arr[i]});
            }
            
        }
        return ans;
    }
};