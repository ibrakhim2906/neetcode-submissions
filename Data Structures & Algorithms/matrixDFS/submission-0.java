class Solution {
    public int countPaths(int[][] grid) {
        HashSet<String>  visit = new HashSet<>();

        int res = dfs(grid, 0,0, visit);

        return res;
    }

    public int dfs(int[][] grid, int r, int c, HashSet<String> visit) {
        int ROWS = grid.length;
        int COLS = grid[0].length;

        if (r<0 || c<0 || r>=ROWS || c>=COLS) {
            return 0;
        }
        
        if (visit.contains(r+","+c) || grid[r][c]==1) {
            return 0;
        }

        if (r==ROWS-1 && c==COLS-1) {
            return 1;
        }

        visit.add(r+","+c);

        int count=0;
        
        count+=dfs(grid, r+1, c, visit);
        count+=dfs(grid, r-1, c, visit);
        count+=dfs(grid, r, c+1, visit);
        count+=dfs(grid, r, c-1, visit);

        visit.remove(r+","+c);

        return count;

        
    }
}
