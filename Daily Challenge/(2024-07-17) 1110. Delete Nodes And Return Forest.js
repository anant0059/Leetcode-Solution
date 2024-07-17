/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
 var delNodes = function(root, to_delete) {
    let res = []
    let mp = {}
    for(i of to_delete) {
        mp[i] = 1
    }
    del = function(curr_root, parent) {
        if(curr_root == null) return
        if(parent && mp[curr_root.val] != 1) res.push(curr_root)
        if(mp[curr_root.val] == 1) {
            del(curr_root.left, 1)
            del(curr_root.right, 1)
        } else {
            del(curr_root.left, 0)
            del(curr_root.right, 0)
        }
        if(curr_root.left && mp[curr_root.left.val]) curr_root.left=null;
        if(curr_root.right && mp[curr_root.right.val]) curr_root.right=null;
    }
    del(root, 1)
    console.log(mp)
    return res
};