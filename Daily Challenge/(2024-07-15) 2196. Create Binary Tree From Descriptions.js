/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function(descriptions) {
    let n = descriptions.length
    let dic = {}, freq = {}
    for(let i=0; i<n; i++) {
        let tmp
        let parent = descriptions[i][0]
        let child = descriptions[i][1]
        let isLeft = descriptions[i][2]
        if(dic[parent] == null) {
            tmp = new TreeNode(parent)
            dic[parent] = tmp
            // console.log("tmp1", tmp)
        }
        
        if(dic[child] == null) {
            tmp = new TreeNode(child)
        } else {
            tmp = dic[child]
        }
        
        if(isLeft == 1) {
            dic[parent].left = tmp
        } else {
            dic[parent].right = tmp
        }
        dic[child] = tmp

        if(!freq[child]) {
            freq[child] = 1
        } else {
            freq[child]++
        }
    }
    // console.log("freq", freq)
    for(let i=0; i<n; i++){
        // console.log("freq", freq[descriptions[i][1]])
        if(!freq[descriptions[i][0]]) {
            // console.log(descriptions[i][0])
            return dic[descriptions[i][0]]
        }
    }
    // console.log(n, dic)
    return null
};