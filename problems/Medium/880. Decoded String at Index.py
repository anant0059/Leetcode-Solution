# class Solution:
#     def decodeAtIndex(self, s: str, k: int) -> str:
#         res = ""
#         for i in s:
#             if i >= '2' and i <= '9':
#                 # print(ord(i)-ord('0'), res)
#                 temp = res
#                 if (len(res) * (ord(i)-ord('0'))) >= k:
#                     return res[(k%len(res)) - 1]
#                 for _ in range(ord(i)-ord('0')-1):
#                     if len(res) + len(temp) >= k:
#                         return temp[k-len(res)-1]
#                     res += temp
#             else:
#                 res += i
#         return res[k-1]
class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        total_length = 0

        # Calculate the total length of the decoded string
        for char in s:
            if char.isdigit():
                total_length *= int(char)
            else:
                total_length += 1

        # Traverse the string in reverse to find the character at index k
        for char in reversed(s):
            k %= total_length  # Reduce index based on the length

            # Check if the current character is the answer
            if k == 0 and char.isalpha():
                return char

            # Update the length based on the current character
            if char.isdigit():
                total_length //= int(char)
            else:
                total_length -= 1