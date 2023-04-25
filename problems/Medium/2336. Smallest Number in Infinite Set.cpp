class SmallestInfiniteSet {
    int curr_int = 1;
    priority_queue <int, vector<int>, greater<int>> st;
    map<int,int> mp;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(st.size()) {
            int tmp = st.top();
            mp[tmp] = 0;
            st.pop();
            return tmp;
        }
        return curr_int++;
    }
    
    void addBack(int num) {
        if(num < curr_int && mp[num] == 0) {
            st.push(num);
            mp[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */