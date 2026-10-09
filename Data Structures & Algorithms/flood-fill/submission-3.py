class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        start_color = image[sr][sc]

        if start_color == color:
            return image
        
        def dfs(grid: list[list[int]], r: int, c: int, color: int, start_color: int):
            
            ROWS, COLS = len(grid), len(grid[0])

            if (r<0 or c<0 or r==ROWS or c==COLS or grid[r][c]!=start_color):
                return
            
            if grid[r][c]==start_color:
                grid[r][c]=color
            
            directions=[[0,1],[0,-1],[1,0],[-1,0]]

            for dr, dc in directions:
                dfs(grid, r+dr, c+dc, color, start_color)

        dfs(image, sr, sc, color, start_color)

        return image


            