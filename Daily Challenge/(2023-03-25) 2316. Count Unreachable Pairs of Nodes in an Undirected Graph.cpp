class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0;
        unordered_map < int, vector < int > > graph;
        for ( auto i : edges ) 
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector < int > visited( n, 0 );
        vector < long long > unconnected_graph;
        vector < int > counted( n, 0 );

        queue < int > q;
        long long total_sum = 0;

        for ( int i = 0; i < n; ++i){
            if( visited[i] )
            {
                continue;
            }
            q.push(i);
            int length = 0;
            while( q.size() )
            {
                int node = q.front();
                q.pop();
                if( visited[node] ) continue;
                visited[node] = 1;
                for ( auto child : graph[node] )
                {
                    if( visited[child] == 0 )
                    {
                        if ( counted[child] == 0 )
                        {
                            length++;
                            counted[child] = 1;
                        }
                        q.push(child);
                        // cout<<child<<" "<<length;
                    }
                }
                // cout<<endl;
            }
            unconnected_graph.push_back( length + 1 );
            total_sum += length + 1;
        }

        for( auto i : unconnected_graph )
        {
            res += ( total_sum - i ) * i;
            //cout<<i<<endl;
        }

        return res/2;
    }
};