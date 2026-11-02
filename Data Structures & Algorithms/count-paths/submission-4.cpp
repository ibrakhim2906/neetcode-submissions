class Solution {
public:

    int ROWS, COLS; 
    
    int uniquePaths(int m, int n) { 
        vector<vector<int>> grid(m, vector<int>(n, -1));

        ROWS = m;
        COLS = n;

        return dfs(grid, 0, 0);


        
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r==ROWS || c==COLS)
        {
            return 0;
        }

        if (r==ROWS-1 || c == COLS-1)
        {
            return 1;
        }

        if (grid[r][c] != -1)
        {
            return grid[r][c];
        }

        return grid[r][c] = dfs(grid, r+1, c)+
            dfs(grid, r, c+1);

        
    }
};
