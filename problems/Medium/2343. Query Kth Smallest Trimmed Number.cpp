class Solution {

public:

    template<typename T>
    void print_arr(vector<T> &v)
    {
        for(auto &x: v)
            cout<<x<<" ";
        cout<<endl;
    }

    void radix_sort(vector<vector<int>> &memo, vector<string> &nums, int n)
    {
       
        vector<int> freq(10);
        vector<string> next(nums.begin(), nums.end());
        vector<string> curr(nums.begin(), nums.end());
       
        for(int i=0; i < n; i++)
        {
            std::fill(freq.begin(), freq.end(), 0);

            int place = curr[0].size() - 1 - i;
            
          
            char base = '0';

            // count occurence of digit for given place in array
            for(auto &x: curr)
            {
                int digit = (x[place] - base);
               
                freq[digit]++;
            }

            //print_arr(freq);

            // find next available index for place's digit in sorted array
            auto next_idx = 0;
            for(int i = 0; i<freq.size(); i++)
            {
                int count = freq[i];
                freq[i] = next_idx;
                next_idx += count;
            }

            //print_arr(freq);

            

            // sort array
            for(int j=0; j<curr.size(); j++)
            {
                auto x = curr[j];
                int digit = (x[place] - base);

                // get index for digit
                int idx = freq[digit];

                // store the index of original element to next sorted position
                memo[i+1][idx] = memo[i][j];
                next[idx] = x;

                // increase index for next time digit happen
                freq[digit]++; 
            }
            
            curr = next;
        }
  
    
    }


    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        auto n = nums[0].size();
        vector<vector<int>> memo(n+1, vector<int>(nums.size()));
       
        for(int i=0;i<nums.size(); i++)
          memo[0][i] = i;
       

        radix_sort(memo, nums,  n);

        vector<int> res(queries.size());

        
        
        int i=0;
        for(auto &q: queries)
        {
            auto k = q[0];
            auto t = q[1];

            res[i++] = memo[t][k-1];
        }

        return res;
    }

 
};