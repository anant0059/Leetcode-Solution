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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(q1.size() || q2.size()){
            TreeNode* left=q1.front();
            TreeNode* right=q2.front();
            q1.pop();
            q2.pop();
            if(left==NULL && right==NULL){
                continue;
            }
            if(left==NULL || right==NULL){
                return false;
            }
            if(left->val != right->val){
                return false;
            }
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};