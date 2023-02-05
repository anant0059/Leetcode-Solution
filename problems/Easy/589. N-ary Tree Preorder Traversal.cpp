/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void find_preorder(Node* root, vector<int>& res){
        if(root==NULL) return;
        res.push_back(root->val);
        for(auto i:root->children){
            find_preorder(i, res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        find_preorder(root, res);
        return res;
    }
};