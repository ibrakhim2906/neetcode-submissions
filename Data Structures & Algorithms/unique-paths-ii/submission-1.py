class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        ROWS, COLS = len(obstacleGrid), len(obstacleGrid[0])

        cache = [[-1]*COLS for _ in range(ROWS)]

        def top_down(grid: list[list[int]], r, c, ROWS, COLS):
            if r==ROWS or c==COLS or grid[r][c]==1:
                return 0
            
            if r==ROWS-1 and c==COLS-1:
                return 1
            
            if cache[r][c]!=-1:
                return cache[r][c]

            cache[r][c]=(top_down(grid, r+1, c, ROWS, COLS)+top_down(grid,r,c+1,ROWS, COLS))

            return cache[r][c]

        
        return top_down(obstacleGrid, 0, 0, ROWS, COLS)