/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function(s) {
    let n = s.length;
    let stack = [];
    for(let i=0; i<n; i++) {
        if(s[i]=='(') {
            stack.push('(');
        } else if(s[i]==')') {
            let tmp = ""
            while(stack.length > 0 && stack[stack.length-1] != '(') {
                // console.log(stack[stack.length-1])
                tmp += [...stack.pop()].reverse().join("")
            }
            stack.pop();
            // tmp = [...tmp].reverse().join("")
            stack.push(tmp);
        } else {
            stack.push(s[i])
        }
    }
    let res = ""
    for(let i=0; i<stack.length; i++) {
        res += stack[i]
    }
    return res
};