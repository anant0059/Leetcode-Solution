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
    int ans = INT_MAX, prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) {
            return ans;
        }

        getMinimumDifference(root -> left);

        if( prev >= 0 ) {
            ans = min(ans, abs(root -> val - prev));
        }
        prev = root -> val;
        
        getMinimumDifference(root -> right);
        
        return ans;
    }
};