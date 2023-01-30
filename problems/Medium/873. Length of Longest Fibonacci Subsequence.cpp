class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int> mp;
        for(auto i:arr) mp.insert(i);
        int ans=0,n=arr.size(),first,second,count,tmp;
        //cout<<n<<endl;
        //return ans;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                first=arr[i];
                second=arr[j];
                count=0;
                tmp=first+second;
                while(mp.find(tmp)!=mp.end()){
                    ++count;
                    first=second;
                    second=tmp;
                    tmp=first+second;
                }
                if(ans<count) ans=count;
            }
        }
        if(ans) return ans+2;
        return 0;
    }
};