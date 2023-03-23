class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if( size < n - 1 ) return -1;
        vector<vector<int>> graph( n );
        for( auto i : connections ){
            graph[i[0]].push_back( i[1] );
            graph[i[1]].push_back( i[0] );
        }

        vector<int> visited( n, 0 );
        queue<int> q;
        int res = 0;

        for( int i = 0; i < n; ++i ){
            if(visited[i]) continue;
            res++;
            q.push(i);
            //visited[i] = 1;
            while(q.size()){
                int tmp = q.front();
                q.pop();
                if( visited[tmp] ) continue;
                for( auto node : graph[tmp] ){
                    if( visited[node] == 0 ) q.push(node);
                }
                visited[tmp] = 1;
            }
        }
        return res - 1 ;
    }
};