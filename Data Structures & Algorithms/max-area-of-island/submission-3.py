class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        areas = []

        visit = set()

        ROWS, COLS = len(grid), len(grid[0])

        def dfs(grid: list[list[int]], r: int,c: int, area: int, visit: set[tuple(int,int)]) -> int:

            if (min(r,c)<0 or r == ROWS or c == COLS or grid[r][c]==0 or (r,c) in visit):
                return 0

            visit.add((r,c))

            area = 1

            area += dfs(grid, r+1, c, area, visit)
            area += dfs(grid, r-1, c, area, visit)
            area += dfs(grid, r, c+1, area, visit)
            area += dfs(grid, r, c-1, area, visit)

            return area

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c]==1 and (r,c) not in visit:
                    areas.append(dfs(grid, r, c, 0, visit))

        return max(areas) if len(areas)>0 else 0

            
            