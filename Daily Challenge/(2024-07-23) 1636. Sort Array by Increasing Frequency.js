/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function(nums) {
    let obj = {}
    // Count the frequency of each number in the array
    for (let num of nums) {
        obj[num] = (obj[num] || 0) + 1;
    }

    // Sort the array based on frequency in descending order, and in case of ties, in descending order of the numbers
    return nums.sort((a, b) => obj[a] === obj[b] ? b - a : obj[a] - obj[b]);
};