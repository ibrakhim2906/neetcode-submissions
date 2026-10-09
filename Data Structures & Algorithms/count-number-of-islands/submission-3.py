class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        ROWS, COLS = len(grid), len(grid[0])

        def dfs(grid: list[list[int]], r: int, c: int):
            
            if (r<0 or c<0 or c==COLS or r==ROWS or grid[r][c]=="0"):
                return

            grid[r][c]="0"

            directions = [[0,1],[0,-1],[1,0],[-1,0]]

            for dr, dc in directions:
                dfs(grid, r+dr, c+dc)

        count = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c]=="1":
                    dfs(grid, r, c)
                    count+=1
        
        return count