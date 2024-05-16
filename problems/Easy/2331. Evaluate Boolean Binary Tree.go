/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func evaluateTree(root *TreeNode) bool {
    if root == nil {
        return false
    }
    if root.Left != nil {
        evaluateTree(root.Left)
    }
    if root.Right != nil {
        evaluateTree(root.Right)
    }
    if root.Val == 2 {
        root.Val = root.Left.Val | root.Right.Val
    } else if root.Val == 3 {
        root.Val = root.Left.Val & root.Right.Val
    }
    if root.Val == 0 {
        return false
    }
    return true
}