class Solution:
	def shortestPathLength(self, graph: List[List[int]]) -> int:

		length = len(graph)

		result = 0

		visited_node = []

		queue = []  

		for i in range(length):
			visited_node.append(set([1<<i]))
			queue.append([i,1<<i])

		while queue:

			result = result + 1

			new_queue = []

			for node, value in queue:

				for neigbour_node in graph[node]:

					mid_node = (1<<neigbour_node)|value

					if mid_node not in visited_node[neigbour_node]:

						if mid_node+1 == 1<<length:

							return result

						visited_node[neigbour_node].add(mid_node)

						new_queue.append([neigbour_node, mid_node])

			queue = new_queue

		return 0