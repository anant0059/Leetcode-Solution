class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(),currentNo=1,i=0,j=0;
        while(i<n && j<k){
            if(arr[i]==currentNo) i++;
            else j++;
            currentNo++;
        }
        while(j<k) j++,currentNo++;
        return currentNo-1;
    }
};