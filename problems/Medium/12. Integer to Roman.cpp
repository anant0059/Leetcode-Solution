class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),i=0,j=n-1,mx=0;
        while(i<j){
            mx=max(mx,abs(min(height[i],height[j])*(j-i)));
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return mx;
    }
};