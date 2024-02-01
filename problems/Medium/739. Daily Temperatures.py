class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0]*n
        st = [n-1]
        print(st)
        for i in range(n-2,-1,-1):
            print(i)
            while(len(st) >0 and temperatures[i]>=temperatures[st[-1]]):
                st.pop()
            if len(st):
                res[i]=st[-1]-i
            st.append(i)
        return res
