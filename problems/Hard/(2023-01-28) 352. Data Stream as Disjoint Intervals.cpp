class SummaryRanges {
    vector<vector<int>> res;
    vector<int> values;
public:
    SummaryRanges() {
        vector<int> v(10001,0);
        values=v;
    }
    
    void addNum(int value) {
        values[value]=1;
    }
    
    vector<vector<int>> getIntervals() {
        res={};
        int last=-1,curr=-1;
        for(int i=0;i<=10000;++i){
            if(values[i]){
                if(last==-1) last=curr;
                curr=i;
            }
            else{
                if(curr!=-1){
                    if(last==-1){
                        res.push_back({curr,curr});
                    }
                    else{
                        res.push_back({last,curr});
                    }
                }
                curr=-1;
                last=-1;
            }
        }
        if(curr!=-1){
            if(last==-1){
                res.push_back({curr,curr});
            }
            else{
                res.push_back({last,curr});
            }
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */