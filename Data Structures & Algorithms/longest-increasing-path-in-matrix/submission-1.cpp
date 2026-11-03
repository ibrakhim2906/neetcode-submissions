class Solution {
public:

    vector<vector<int>> memo;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int ROWS = matrix.size(), COLS = matrix[0].size(), maxVal = 0;
        
        memo.assign(ROWS, vector<int>(COLS, -1));

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                maxVal = max(maxVal, dfs(r,c,matrix, INT_MIN));
            }
        }

        return maxVal;


        
    }

    int dfs(int r, int c, vector<vector<int>>& matrix, int prevVal)
    {
        if (r<0 || c<0 || r>=matrix.size() || c>=matrix[0].size() || matrix[r][c] <= prevVal)
        {
            return 0;
        }

        if (memo[r][c] != -1)
        {
            return memo[r][c];
        }

        int res = 1;

        for (auto d : directions)
        {
            res = max(res, 1+dfs(r+d[0], c+d[1], matrix, matrix[r][c]));
        }

        return memo[r][c] = res;
    }

    
};
