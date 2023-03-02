class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0, i=0, n=chars.size(), start=0;
        while(i<n){
            char tmp=chars[i];
            int count=0;
            while(i<n && chars[i]==tmp){
                count++;
                i++;
            }
            chars[start++]=tmp;
            ++ans;
            if(count>1){
                string temp=to_string(count);
                ans+=temp.size();
                for(auto c:temp){
                    chars[start++]=c;
                }
            }
        }
        return ans;
    }
};