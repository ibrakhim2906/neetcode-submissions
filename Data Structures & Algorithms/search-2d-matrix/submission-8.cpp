class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //    0 0 0 0 0
    //    0 0 0 0 0
    //    0 0 0 1 0
    //    0 0 0 0 0
    //    
    //    row = 2, col = 2, in-line = 13 (0 indexed), m(rows) = 4, n(cols) = 5

        int ROWS = matrix.size(), COLS = matrix[0].size();

        int l = 0, row = ROWS * COLS -1;

        while (l<=row)
        {
            int m = l+(row-l)/2;
            int r = m / COLS, c = m % COLS;

            if (matrix[r][c] < target)
            {
                l = m+1;
            } else if (matrix[r][c] > target)
            {
                row = m-1;
            } else {
                return true;
            }
        }

        return false;
    }
        
};
