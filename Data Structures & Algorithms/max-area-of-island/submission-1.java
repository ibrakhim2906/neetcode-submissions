class Solution {
    private int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    public int maxAreaOfIsland(int[][] grid) {
        int ROWS = grid.length;
        int COLS = grid[0].length;

        int max = 0;

        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++) {
                if (grid[r][c]==1) {
                    int current = currArea(grid, r, c);
                    if (max<current) {
                        max=current;
                    }
                }
            }
        }
        return max;
    }

    public int currArea(int[][] grid, int r, int c) {
        if (r<0 || c<0 || r>=grid.length || c>=grid[0].length || grid[r][c]==0) {
            return 0;
        }

        grid[r][c]=0;

        int area=1;

        for (int[] dir : directions) {
            area+=currArea(grid, r+dir[0], c+dir[1]);
        }

        return area;
    }
}
