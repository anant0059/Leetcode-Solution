/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map< Node*, Node* > mp;
public:
    Node* cloneGraph(Node* node) {
        if( node == NULL )
        {
            return NULL;
        }

        if( !mp[node] )
        {
            mp[node] = new Node( node -> val );
            for( int i = 0; i < node -> neighbors.size(); ++i )
            {
                mp[node] -> neighbors.push_back( cloneGraph( node -> neighbors[i] ) );
            }
        }

        return mp[node];
    }
};