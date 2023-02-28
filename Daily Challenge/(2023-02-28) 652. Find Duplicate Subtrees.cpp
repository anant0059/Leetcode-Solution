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
    string serialize(TreeNode* root, map<string, int> &mp, map<string, TreeNode*> &mp1) {
        if (root == NULL) return "";
        string s = "(" + serialize(root->left, mp, mp1) + to_string(root->val) + serialize(root->right, mp, mp1) + ")";
        mp[s]++;
        mp1[s]=root;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> mp;
        map<string, TreeNode*> mp1;
        serialize(root, mp, mp1);
        vector<TreeNode*> res;
        for(auto i:mp){
            if(i.second>1){
                res.push_back(mp1[i.first]);
            }
        }
        return res;
    }
};