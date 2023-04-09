class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        while(--n){
            string temp="";
            int sze=res.size();
            
            for(int j=0;j<sze;){
                int count=0,left=j,right=j;
                while(right<sze && res[left]==res[right]){
                    count++;
                    right++;
                }
                j=right;
                
                temp+=to_string(count)+res[left];
            }
            res=temp;
        }
        return res;
    }
};