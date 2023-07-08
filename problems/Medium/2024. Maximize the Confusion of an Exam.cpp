class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        cout<< n << endl;
        queue<int> q;
        int tmp = 0;
        int res = 0;
        int start = -1;
        for(int i = 0; i < n; ++i) {
            if(answerKey[i] == 'F') {
                if(tmp < k) {
                    ++tmp;
                }
                else {
                    int temp = q.front();
                    start = temp;
                    q.pop();
                }
                q.push(i);
            }
            res = max(res, i - start);
        }
        queue<int> qq;
        tmp = 0;
        start = -1;
        for(int i = 0; i < n; ++i) {
            if(answerKey[i] == 'T') {
                if(tmp < k) {
                    ++tmp;
                }
                else {
                    int temp = qq.front();
                    start = temp;
                    qq.pop();
                }
                qq.push(i);
            }
            // cout<< i - start << " " << i << " " << start <<endl;
            res = max(res, i - start);
        }
        return res;
    }
};
