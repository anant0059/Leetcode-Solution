/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func rrl(root *TreeNode, prev int) int {
    if root == nil {
        return prev
    }
    right := rrl(root.Right, prev)
    root.Val = root.Val + right
    left := rrl(root.Left, root.Val)
    return left
}
func bstToGst(root *TreeNode) *TreeNode {
    rrl(root, 0)
    return root
}