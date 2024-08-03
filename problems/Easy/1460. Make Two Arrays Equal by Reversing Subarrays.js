/**
 * @param {number[]} targetArray
 * @param {number[]} currentArray
 * @return {boolean}
 */
var canBeEqual = function(targetArray, currentArray) {
    if (targetArray.length !== currentArray.length) {
        return false;
    }

    const count = new Array(1001).fill(0);
    for (let i = 0; i < targetArray.length; i++) {
        count[targetArray[i]]++;
        count[currentArray[i]]--;
    }

    for (let c of count) {
        if (c !== 0) {
            return false;
        }
    }

    return true;
};