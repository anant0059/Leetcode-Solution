class Solution:
    def candy(self, ratings: List[int]) -> int:
      l = len(ratings)
      res = [1]*l
      for i in range(1, l):
        if ratings[i] > ratings[i-1]:
          res[i] = res[i-1] + 1
      
      count = res[l-1]
      for i in range(l-2, -1, -1):
        if ratings[i] > ratings[i+1]:
          res[i] = max(res[i+1] + 1, res[i])
        count = count + res[i]
      print(res)
      return count