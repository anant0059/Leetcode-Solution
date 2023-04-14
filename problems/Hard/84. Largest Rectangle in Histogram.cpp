class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n,n), left(n,-1);
        stack<int>s,s1;
        for(int i=0;i<n;++i){
            if(s.empty()){
                s.push(i);
            }
            else{
                if(heights[i]<=heights[s.top()]){
                    while(!s.empty() && heights[i]<heights[s.top()]){
                        right[s.top()]=i;
                        s.pop();
                    }
                }
                s.push(i);
            }
        }
        
        for(int i=n-1;i>-1;--i){
            if(s1.empty()){
                s1.push(i);
            }
            else{
                if(heights[i]<=heights[s1.top()]){
                    while(!s1.empty() && heights[i]<heights[s1.top()]){
                        left[s1.top()]=i;
                        s1.pop();
                    }
                }
                s1.push(i);
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            //cout<<left[i]<<" "<<right[i]<<endl;
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};