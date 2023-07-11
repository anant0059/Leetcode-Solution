/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> res;
    map<TreeNode*, int> mp;

    void findLowerNode(TreeNode* node, int k, int distance) {
        if(node == NULL || distance > k || mp[node]) {
            return;
        }
        ++mp[node];
        if(distance == k) {
            res.push_back(node->val);
        }
        findLowerNode(node->left, k, distance + 1);
        findLowerNode(node->right, k, distance + 1);
    }

    int findUpperNode(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) {
            return 0;
        }
        if(root -> left == target || root -> right == target) {
            findLowerNode(root, k, 1);
            return 1;
        }
        int left = findUpperNode(root -> left, target, k);
        int right = findUpperNode(root -> right, target, k);

        if(left > 0) {
            findLowerNode(root, k, left + 1);
            return left + 1;
        }
        if(right > 0) {
            findLowerNode(root, k, right + 1);
            return right + 1;
        }
        return 0;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findLowerNode(target, k, 0);

        findUpperNode(root, target, k);
        

        return res;
    }
};