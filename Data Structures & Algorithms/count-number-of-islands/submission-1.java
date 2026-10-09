class Solution {

    private int[][] directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    public int numIslands(char[][] grid) {
        int ROWS = grid.length;
        int COLS = grid[0].length;

        int count = 0;

        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++) {
                if (grid[r][c]=='1') {
                    dfs(grid, r, c);
                    count++;
                }
            }
        }

        return count;
        
    }

    public void dfs(char[][]grid, int r, int c) {
        if (r<0 || c<0 || r>=grid.length || c>=grid[0].length || grid[r][c]=='0') {
            return;
        }

        grid[r][c]='0';

        for (int[] dir : directions) {
            dfs(grid, r+dir[0], c+dir[1]);
        }
    }
}
