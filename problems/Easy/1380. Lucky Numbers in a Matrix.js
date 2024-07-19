/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function(matrix) {
    let rows = matrix.length;
    let cols = matrix[0].length;

    let row_maximum_of_minimums = 0;
    for (let row of matrix) {
        let row_minimum = Math.min(...row);
        row_maximum_of_minimums = Math.max(row_maximum_of_minimums, row_minimum);
    }

    let col_minimum_of_maximums = Infinity;
    for (let col_ind = 0; col_ind < cols; ++col_ind) {
        let col_maximum = 0;
        for (let row_ind = 0; row_ind < rows; ++row_ind) {
            col_maximum = Math.max(col_maximum, matrix[row_ind][col_ind]);
        }
        col_minimum_of_maximums = Math.min(col_minimum_of_maximums, col_maximum);
    }

    return row_maximum_of_minimums === col_minimum_of_maximums ? [col_minimum_of_maximums] : [];
};