/**
 * @param {number[][]} customers
 * @return {number}
 */

var averageWaitingTime = function(customers) {
    let n = customers.length
    customers.sort((a, b) => a[0] > b[0])
    console.log(customers, n)
    let curr = 0;
    let res = 0;
    for (let i = 0; i < n; i++) {
        if (curr <= customers[i][0]) {
            res += customers[i][1];
            curr = customers[i][0] + customers[i][1];
        } else {
            res += (curr - customers[i][0] + customers[i][1]);
            curr += customers[i][1];
        }
    }
    return res / n;
};