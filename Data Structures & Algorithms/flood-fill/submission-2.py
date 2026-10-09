class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        start_color = image[sr][sc]

        if start_color == color:
            return image
        
        def dfs(grid: list[list[int]], 
                start_row: int, 
                start_col: int, 
                color: int,
                start_color: int) -> None:
            
            ROWS, COLS = len(image), len(image[0])

            if (min(start_row,start_col)<0 or start_row == ROWS or start_col == COLS or image[start_row][start_col]!=start_color):
                return
            
            if (image[start_row][start_col]==start_color):
                image[start_row][start_col]=color


            dfs(image, start_row+1, start_col, color, start_color)
            dfs(image, start_row-1, start_col, color, start_color)
            dfs(image, start_row, start_col+1, color, start_color)
            dfs(image, start_row, start_col-1, color, start_color)


        dfs(image, sr, sc, color, start_color)

        return image