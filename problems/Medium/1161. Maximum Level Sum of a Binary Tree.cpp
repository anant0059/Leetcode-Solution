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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int res = 1;
        int level = 0;
        int mx_sm = root -> val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int sm = 0;
            cout<<sz<<endl;
            while(sz) {
                sm += q.front() -> val;
                if(q.front() -> left) {
                    q.push(q.front() -> left);
                }
                if(q.front() -> right) {
                    q.push(q.front() -> right);
                }
                q.pop();
                --sz;
            }
            ++level;
            if(sm > mx_sm) {
                mx_sm = sm;
                res = level;
            }
        }
        return res;
    }
};