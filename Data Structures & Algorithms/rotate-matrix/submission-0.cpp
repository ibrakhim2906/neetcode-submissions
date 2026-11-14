class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        for (int r = 0 ; r < ROWS; r++)
        {
            for (int c = r+1 ; c < COLS; c++)
            {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (int r = 0; r < ROWS; r++)
        {
            reverse(matrix[r].begin(), matrix[r].end());
        }
        
    }
};
