class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        memo = {}

        def recursion(i, j):
            
            if i==len(text1) or j==len(text2):
                return 0

            if (i,j) in memo:
                return memo[(i,j)]

            if text1[i]==text2[j]:
                memo[(i,j)] = 1 + recursion(i+1, j+1)
            else:
                memo[(i,j)] = max(recursion(i+1, j), recursion(i, j+1))
            
            return memo[(i,j)]
        
        return recursion(0,0)

            

