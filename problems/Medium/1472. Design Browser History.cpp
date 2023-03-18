class BrowserHistory {
    // string homepage;
    vector<string> v;
    int ind=0;
    // int last=0;
public:
    BrowserHistory(string homepage) {
        // this-> homepage=homepage;
        ind++;
        v.push_back(homepage);
        // last++;
    }
    
    void visit(string url) {
        ind++;
        v.resize(ind);
        v[ind-1]=url;
        // cout<<ind<<endl;
        // if(ind>=v.size()){
        //     v.push_back(url);
        //     ind++;
        //     last=ind;
        // }
        // else{
        //     v[ind]=url;
        //     ind++;
        //     last=max(last,ind);
        // }
    }
    
    string back(int steps) {
        if(ind-steps>0){
            // int tmp=ind;
            ind=ind-steps;
            // cout<<ind<<" "<<steps<<" "<<ind-1<<endl;
            // cout<<v[ind-1]<<endl;
            // for(auto i:v) cout<<i<<endl;
            return v[ind-1];
        }
        ind=1;
        return v[0];
    }
    
    string forward(int steps) {
        if(ind+steps<=v.size()){
            int tmp=ind;
            ind=ind+steps;
            return v[tmp+steps-1];
        }
        ind=v.size();
        return v[v.size()-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */