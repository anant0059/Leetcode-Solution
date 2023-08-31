class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # range_taps = [0]*(n+1)
        # for i in range(n+1):
        #     if i - ranges[i] < 0:
        #         tmp_range_left = 0
        #     else:
        #         tmp_range_left = i - ranges[i]
        #     if i + ranges[i] > n:
        #         tmp_range_right = n
        #     else:
        #         tmp_range_right = i + ranges[i]
        #     range_taps[tmp_range_left] = max(tmp_range_right, range_taps[tmp_range_left])
        # print(range_taps)
        # dp = [n+1]*(n+1)
        # if range_taps[0] == 0:
        #     return -1
        # dp[0] = 1
        # print(dp)
        # mx_range_till_now = range_taps[0]
        # min_steps_till_now = 1
        # dp[range_taps[0]] = 1
        # for i in range(1, n+1):
        #     if mx_range_till_now < i and range_taps[i] == 0:
        #         return -1
        #     dp[i] = min(dp[i], min_steps_till_now)
        #     dp[range_taps[i]] = min(dp[range_taps[i]], dp[i] + 1)
        #     mx_range_till_now = max(mx_range_till_now, range_taps[i])
        #     min_steps_till_now = min(min_steps_till_now, dp[range_taps[i]])
        #     print(dp)
        # print("ho")
        # if dp[n] == n+1:
        #     return -1
        # return dp[-1]

        max_range = [0] * (n + 1)
        
        for i in range(len(ranges)):
            left = max(0, i - ranges[i])
            right = min(n, i + ranges[i])
            max_range[left] = max(max_range[left], right)
        
        end = farthest = taps = 0
        i = 0
        
        while end < n:
            while i <= end:
                farthest = max(farthest, max_range[i])
                i += 1
            
            if farthest <= end:
                return -1  # Unable to cover the entire garden
            
            end = farthest
            taps += 1
        
        return taps