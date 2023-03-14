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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        queue<pair<int, TreeNode*>> q;
        q.push({root->val, root});
        while(q.size()){
            int sz=q.size();
            while(sz--){
                int value = q.front().first;
                TreeNode* temp = q.front().second;
                q.pop();
                if(temp->left==NULL && temp->right==NULL) res+=value;
                if(temp->left) q.push({value*10+temp->left->val, temp->left});
                if(temp->right) q.push({value*10+temp->right->val, temp->right});
            }
        }
        return res;
    }
};