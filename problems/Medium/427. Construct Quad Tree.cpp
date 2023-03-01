/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int cnt=0, n=grid.size();
        for(auto i:grid){
            for(auto j:i){
                if(j==1) cnt++;
            }
        }
        if(cnt==n*n){
            Node* res=new Node(1, 1);
            return res;
        }
        else if(cnt==0){
            Node* res=new Node(0, 1);
            return res;
        }
        vector<vector<int>> topLeft(n/2, vector<int> (n/2, 0));
        vector<vector<int>> topRight(n/2, vector<int> (n/2, 0));
        vector<vector<int>> bottomLeft(n/2, vector<int> (n/2, 0));
        vector<vector<int>> bottomRight(n/2, vector<int> (n/2, 0));

        for(int i=0;i<n/2;++i){
            for(int j=0;j<n/2;++j){
                topLeft[i][j]=grid[i][j];
                topRight[i][j]=grid[i][n/2+j];
                bottomLeft[i][j]=grid[n/2+i][j];
                bottomRight[i][j]=grid[n/2+i][n/2+j];
            }
        }

        Node* tl=construct(topLeft);
        Node* tr=construct(topRight);
        Node* bl=construct(bottomLeft);
        Node* br=construct(bottomRight);
        Node* res = new Node(1, 0, tl, tr, bl, br);
        return res;
    }
};
