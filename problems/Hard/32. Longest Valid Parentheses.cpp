class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = max(maxans, i - stack.top());
                }
            }
        }
        return maxans;
    }
};