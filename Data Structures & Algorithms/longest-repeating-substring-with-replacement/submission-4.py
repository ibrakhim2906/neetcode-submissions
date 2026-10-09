class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        length = 0

        counts = {ch : 0 for ch in s}
        max_freq = 0

        L=0

        for R in range(len(s)):
            
            counts[s[R]]+=1

            max_freq = max(max_freq, counts[s[R]])

            while (R-L+1) - max_freq > k:
                counts[s[L]]-=1
                L+=1
            
            length = max(length, R-L+1)


        return length