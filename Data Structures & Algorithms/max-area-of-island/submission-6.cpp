class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int result{0};
        


        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c< COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    int cur = 0;
                    dfs(grid, r, c, cur);

                    result = max(result, cur);
                }
            }
        }

        return result;
    }


    void dfs(vector<vector<int>>& grid, int r, int c, int& area) 
    {

        int ROWS = grid.size(), COLS = grid[0].size();
        if (r < 0 || c < 0 || r>=ROWS || c>=COLS || grid[r][c] == 0)
        {
            return;
        }

        grid[r][c] = 0;
        area++;

        dfs(grid, r+1, c, area);
        dfs(grid, r-1, c, area);
        dfs(grid, r, c+1, area);
        dfs(grid, r, c-1, area);
    
    }



    
};
