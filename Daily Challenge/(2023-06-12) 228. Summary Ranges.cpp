class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        vector<string> ans;
        int n=arr.size();
        if(n==0) return ans;
        for(int i=0;i<n;){
            int x=i;
            while(i+1<n && (long long)(arr[i+1])-(long long)(arr[i])==1){
                i++;
            }
            if(i==x) {
                ans.push_back(to_string(arr[i]));
            }
            else{
                ans.push_back(to_string(arr[x])+"->"+to_string(arr[i]));
            }
            i++;
        }
        return ans;
    }
};