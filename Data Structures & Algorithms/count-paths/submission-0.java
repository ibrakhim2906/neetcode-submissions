class Solution {
    public int uniquePaths(int m, int n) {
        int[][] cache = new int[m][n];

        return memo(0,0, m, n , cache);
        
    }

    public int memo(int r, int c, int ROWS, int COLS, int[][] cache) {
        if (r==ROWS || c==COLS) {
            return 0;
        }
        if (cache[r][c]>0) {
            return cache[r][c];
        }
        if (r==ROWS-1 && c==COLS-1) {
            return 1;
        }

        cache[r][c]=memo(r+1, c, ROWS, COLS, cache) + memo(r, c+1, ROWS, COLS, cache);

        return cache[r][c];
        
    }
}
