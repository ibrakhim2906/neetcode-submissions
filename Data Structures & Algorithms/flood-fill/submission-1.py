class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        def dfs(grid: list[list[int]], 
                start_row: int, 
                start_col: int, 
                color: int, 
                visit: set[tuple[int,int]],
                start_color: int) -> None:
            
            ROWS, COLS = len(image), len(image[0])

            if (min(start_row,start_col)<0 or start_row == ROWS or start_col == COLS or (start_row,start_col) in visit or image[start_row][start_col]!=start_color):
                return
            
            if (image[start_row][start_col]==start_color):
                image[start_row][start_col]=color

            visit.add((start_row, start_col))

            dfs(image, start_row+1, start_col, color, visit, start_color)
            dfs(image, start_row-1, start_col, color, visit, start_color)
            dfs(image, start_row, start_col+1, color, visit, start_color)
            dfs(image, start_row, start_col-1, color, visit, start_color)

            visit.remove((start_row, start_col))

        dfs(image, sr, sc, color, set(), image[sr][sc])

        return image