class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        if not s:
            return 0
        
        window = set()

        length = 1

        L=0

        for R in range(len(s)):

            while s[R] in window:

                window.remove(s[L])
                L+=1

            window.add(s[R])
            length = max(length, R-L+1)

        return length
                
                
