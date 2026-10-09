class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        ROWS, COLS = len(grid), len(grid[0])
        
        visit = set()

        max_area = 0
        
        def dfs(grid: list[list[int]], r: int, c: int, visit: set) -> int:

            if (r<0 or c<0 or c==COLS or r==ROWS or (r,c) in visit or grid[r][c]==0):
                return 0

            grid[r][c]==0

            visit.add((r,c))
            
            area = 1

            directions = [[1,0], [-1,0], [0,1], [0,-1]]
            
            for dr, dc in directions:
                area+=dfs(grid, r+dr, c+dc, visit)

            return area

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c]==1 and (r,c) not in visit:
                    area = dfs(grid, r, c, visit)

                    max_area = max(max_area,area)

        return max_area
