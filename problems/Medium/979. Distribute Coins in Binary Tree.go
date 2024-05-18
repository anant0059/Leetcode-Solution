/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var res int

 // Helper function to calculate the absolute value
 func abs(x int) int {
	 if x < 0 {
		 return -x
	 }
	 return x
 }
 
 // Main function to distribute coins in the binary tree
 func distributeCoins(root *TreeNode) int {
	 res = 0
	 helper(root)
	 return res
 }
 
 // Helper function to perform the DFS and distribute the coins
 func helper(root *TreeNode) int {
	 if root == nil {
		 return 0
	 }
 
	 leftCoin := helper(root.Left)
	 rightCoin := helper(root.Right)
 
	 res += abs(leftCoin) + abs(rightCoin)
 
	 return (root.Val - 1) + leftCoin + rightCoin
 }
 