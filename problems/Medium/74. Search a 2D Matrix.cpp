class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int t=0,b=n-1,l=0,r=m-1,mid=0;
        while(t<b){
            mid=(t+b)/2;
            if(matrix[mid][m-1]<target) t=mid+1;
            else if(matrix[mid][0]>target) b=mid-1;
            else{
                t=mid;
                break;
            }
        }
        while(l<=r){
            mid=(l+r)/2;
            if(matrix[t][mid]>target) r=mid-1;
            else if(matrix[t][mid]<target) l=mid+1;
            else return 1;
        }
        return 0;
    }
};