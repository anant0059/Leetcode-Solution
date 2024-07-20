/**
 * @param {number[]} rowSum
 * @param {number[]} colSum
 * @return {number[][]}
 */
var restoreMatrix = function(rowSum, colSum) {
    let n = rowSum.length;
    let m = colSum.length;
    let res = Array.from({ length: n }, () => new Array(m).fill(0));
    let i = 0, j = 0;
    while(i < n && j < m) {
        res[i][j] = Math.min(rowSum[i], colSum[j]);

        rowSum[i] -= res[i][j];
        colSum[i] -= res[i][j];

        rowSum[i] == 0 ? i++ : j++;
    }
    return res;
};