class Solution:
    def bestClosingTime(self, customers: str) -> int:
        # left_y = [0]
        # right_y = [0]
        # n = len(customers)
        # tmp = 0
        # for i in customers:
        #     if i == 'N':
        #         tmp += 1
        #     left_y.append(tmp)
        
        # tmp = 0
        # min_penalty = n
        # index = n
        # for i in range(n-1, -1, -1):
        #     if customers[i] == 'Y':
        #         tmp += 1
            
        

        max_score = 0
        score = 0
        right_time = -1
        for i in range(len(customers)):
            score += 1 if customers[i] == 'Y' else -1
            if score > max_score:
                max_score = score
                right_time = i
        return right_time + 1
            