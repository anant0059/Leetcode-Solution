class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        left = right = total = 0
        freq = [0]*3
        while right < len(s):
            freq[ord(s[right]) - ord("a")] += 1

            while self.check(freq):
                total += len(s) - right
                freq[ord(s[left]) - ord("a")] -= 1
                left += 1
            right +=1
        return total
    
    def check(self, freq: list) -> bool:
        return all(f>0 for f in freq)