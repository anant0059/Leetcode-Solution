class Solution {
public:
    string predictPartyVictory(string senate) {
        long long n = senate.size();
        queue<long long> q1, q2;
        for( int i = 0; i < n; ++i ) {
            if( senate[i] == 'R' ) {
                q1.push(i);
            }
            else {
                q2.push(i);
            }
        }
        while( q1.size() && q2.size() ) {
            long long r = q1.front(), d = q2.front();
            q1.pop();
            q2.pop();
            if( r < d ) {
                q1.push(r+n);
            }
            else {
                q2.push(d+n);
            }
        }
        // cout<<q1.size() << " "<<q2.size();
        if(q1.size()) {
            return "Radiant";
        }
        return "Dire";
    }
};