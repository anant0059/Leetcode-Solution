class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(), first=-1, findex=-1, second=-1, sindex=-1, ans=0, count1=0, count2=0;
        for(int i=0;i<n;++i){
            if(first==fruits[i]){
                findex=i;
                count1++;
            }
            else if(second==fruits[i]){
                sindex=i;
                count2++;
            }
            else if(first==-1){
                first=fruits[i];
                findex=i;
                count1=1;
            }
            else if(second==-1){
                second=fruits[i];
                sindex=i;
                count2=1;
            }
            else{
               
                    if(findex>sindex){
                        count1=i-sindex-1;
                        second=fruits[i];
                        sindex=i;
                        count2=1;
                    }
                    else{
                        count2=i-findex-1;
                        first=fruits[i];
                        findex=i;
                        count1=1;
                    }
                
            }
            ans=max(ans, count1+count2);
            //cout<<ans<<" "<<count1<<" "<<count2<<" "<<findex<<" "<<sindex<<endl;
        }
        return ans;
    }
};