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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=1;
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0,root));
        while(!q.empty()){
            
            int n=q.size();
            int frst=q.front().first;
            int last=q.back().first;
            
            for(int i=0;i<n;++i){
                pair<int,TreeNode*> temp=q.front();
                int ind=temp.first-frst;
               
                q.pop();
                
                if(temp.second->left != NULL){
                    q.push(make_pair((long long)2*ind+1,temp.second->left));
                }
                if(temp.second->right != NULL){
                    q.push(make_pair((long long)2*ind+2,temp.second->right));
                }
                
                
            }
            
            ans=max(ans,last-frst+1);
        }
        return ans;
    }
};