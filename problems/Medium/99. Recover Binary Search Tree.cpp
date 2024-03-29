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
   TreeNode*first;
TreeNode*prev;
TreeNode*last;
void inorder(TreeNode*root){
    if(root==NULL) return ;
    inorder(root->left);
    if(prev!=NULL &&  (root->val < prev->val)) {
        if(first==NULL) {// this means that this the first voilation of rule;
            first = prev;
            last = root;
        }
        else 
            last = root;    // if this is the second voilation of rule ;
    }
    prev = root;
    inorder(root->right);
}
void recoverTree(TreeNode* root) {
    first = last = prev = NULL;
    inorder(root);
    if(first && last) swap(first->val, last->val);
}
};