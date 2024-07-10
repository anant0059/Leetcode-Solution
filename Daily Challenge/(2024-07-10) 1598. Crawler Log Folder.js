/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let prev_no_log = 0
    let n = logs.length
    for (let i = 0; i < n; i++) {
        if(logs[i] == "../") {
            if(prev_no_log) {
                prev_no_log--
            }
        } else if (logs[i] == "./") {
            continue
        } else {
            prev_no_log++
        }
    }
    return prev_no_log
};