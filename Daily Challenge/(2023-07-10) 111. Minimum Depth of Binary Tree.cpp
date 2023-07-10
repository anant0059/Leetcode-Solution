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
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(q.size()) {
            int sz = q.size();
            ++res;
            while(sz--) {
                TreeNode* tmp = q.front();
                q.pop();
                if(!tmp->right && !tmp->left) {
                    return res;
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
                if(tmp->left) {
                    q.push(tmp->left);
                }
            }
        }
        return res;
    }
};