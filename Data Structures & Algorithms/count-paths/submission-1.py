class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        cache = [[0]*n for _ in range(m)]

        def top_down(r, c, rows, cols):
            
            if r==rows or c==cols:
                return 0
            
            if cache[r][c]>0:
                return cache[r][c]

            if r==rows-1 and c==cols-1:
                return 1

            cache[r][c] = (top_down(r+1, c, rows, cols)+top_down(r, c+1, rows, cols))

            return cache[r][c]

        return top_down(0,0,m,n)