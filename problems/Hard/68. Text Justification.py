class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        n = len(words)
        res = []
        curr = []
        curr_len = 0
        for i in words :
            if curr_len + len(i) + len(curr) <= maxWidth:
                curr.append(i)
                curr_len += len(i)
            else:
                if len(curr) == 1:
                    curr[0] += ' '*(maxWidth-curr_len)
                else:    
                    even_space = int((maxWidth-curr_len)/(len(curr)-1))
                    extra_space = int((maxWidth-curr_len)%(len(curr)-1))
                    # if(len(curr) == 1):
                    #     extra_space = (maxWidth-curr_len)
                    # print((maxWidth-curr_len), (len(curr)-1 or 1))
                    # print(curr_len)
                    # print(even_space, extra_space)
                    for j in range(len(curr)-1):
                        # print(j)
                        curr[j] += " "*(even_space+(extra_space>0))
                        extra_space -= 1
                res.append("".join(curr))
                curr = [i]
                curr_len = len(i)
        res.append(' '.join(curr)+' '*(maxWidth - curr_len - len(curr)+1))
        return res
