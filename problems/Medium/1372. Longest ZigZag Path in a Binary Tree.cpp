/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = 0;
public:
    int longestZigZag(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        findPath(root, true, 0);
        findPath(root, false, 0);
        return res;
    }
    void findPath(TreeNode* root, bool isLeft, int step) {
        if(root == NULL) {
            return;
        }
        res = max(res, step);
        if(isLeft) {
            findPath(root -> left, false, step + 1);
            findPath(root -> right, true, 1);
        }
        else {
            findPath(root -> left, false, 1);
            findPath(root -> right, true, step + 1);
        }
    }
};