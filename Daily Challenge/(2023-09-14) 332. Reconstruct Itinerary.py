from queue import PriorityQueue
class Solution:
    # def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        # dic = {}
        # for i in tickets:
        #     if i[0] in dic:
        #         dic[i[0]].put(i[1])
        #     else:
        #         q = PriorityQueue()
        #         q.put(i[1])
        #         dic[i[0]] = q
        
        # res = []
        # res.append("JFK")
        # prev = "JFK"
        # print(dic)
        # while prev in dic and dic[prev].qsize():
        #     print(dic[prev])
        #     prev = dic[prev].get()
        #     print(prev)
        #     res.append(prev)
        # return res
	def findItinerary(self, tickets: List[List[str]]) -> List[str]:
		# graph
		g = defaultdict(lambda:[])

		for u,v in tickets:
			# to maintain sort heap
			heapq.heappush(g[u],v)
    # print(g)
		ans = []

		def go(s):
			# check if  any airport need to travel from cur airport
			while g[s]:
				a = heapq.heappop(g[s])
				# lets fly to a new airport
				go(a)
			
			# current journey has no next flight anymore
			ans.append(s)
		
		# let's start the journey
		go("JFK")
		# return with reversing the visited ans
		return ans[::-1]