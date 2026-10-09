class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row checking
        for (vector<char>& row : board) {
            set<char> seen{};

            for (char value : row) {
                if (value == '.') {
                    continue;
                }
                if (seen.contains(value)) {
                    return false;
                }

                seen.insert(value);
            }
        }

        // column checking

        for (int c = 0; c < 9; c++) {
            set<char> seen{};

            for (int r = 0; r < 9; r++) {
                if (board[r][c]== '.') {
                    continue;
                }
                if (seen.contains(board[r][c])) {
                    return false;
                }

                seen.insert(board[r][c]);
            }
        }

        // box checking

        for (int square = 0; square < 9; square++) {
            set<char> seen{};

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;

                    if (board[row][col] == '.') continue;

                    if (seen.contains(board[row][col])) {
                        return false;
                    }

                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
