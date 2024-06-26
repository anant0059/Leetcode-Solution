// TreeNode is a node in a binary search tree
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

// balanceBST balances a binary search tree
func balanceBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	// Step 1: Create the backbone (vine)
	vineHead := &TreeNode{Right: root}
	current := vineHead
	for current.Right != nil {
		if current.Right.Left != nil {
			rightRotate(current, current.Right)
		} else {
			current = current.Right
		}
	}

	// Step 2: Count the nodes
	nodeCount := 0
	current = vineHead.Right
	for current != nil {
		nodeCount++
		current = current.Right
	}

	// Step 3: Create a balanced BST
	m := int(math.Pow(2, math.Floor(math.Log2(float64(nodeCount+1)))) - 1)
	makeRotations(vineHead, nodeCount-m)
	for m > 1 {
		m /= 2
		makeRotations(vineHead, m)
	}

	balancedRoot := vineHead.Right
	return balancedRoot
}

// Function to perform a right rotation
func rightRotate(parent, node *TreeNode) {
	tmp := node.Left
	node.Left = tmp.Right
	tmp.Right = node
	parent.Right = tmp
}

// Function to perform a left rotation
func leftRotate(parent, node *TreeNode) {
	tmp := node.Right
	node.Right = tmp.Left
	tmp.Left = node
	parent.Right = tmp
}

// Function to perform a series of left rotations to balance the vine
func makeRotations(vineHead *TreeNode, count int) {
	current := vineHead
	for i := 0; i < count; i++ {
		tmp := current.Right
		leftRotate(current, tmp)
		current = current.Right
	}
}
