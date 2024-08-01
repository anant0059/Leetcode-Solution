/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
    let res = 0
    for(i of details) {
        let tmp = i[11]+i[12]
        if(tmp > 60) {
            res++;
        }
        // console.log(tmp)
    }
    return res;
};