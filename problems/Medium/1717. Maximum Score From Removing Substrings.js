/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
 var maximumGain = function(s, x, y) {
    if (y > x) {
        let tmp = x
        x = y
        y = tmp
        s = s.split('').reverse().join('');
    }
    // console.log(x, y, s)
    let len = s.length, a = 0, b = 0;
    let res = 0;
    for(let i=0;i<len;++i) {
        if (s[i] == 'a') {
            // console.log('a',i)
            ++a;
        } else if (s[i] == 'b') {
            // console.log('b',i)
            if (a > 0) {
                --a;
                res += x
            } else {
                ++b;
            }
        } else {
            // console.log(i, a, b)
            res += Math.min(a, b)* y
            a = 0
            b = 0
        }
    }
    res += Math.min(a, b)* y
    return res
};