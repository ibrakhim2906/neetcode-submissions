class Solution {

    int calcSquare(int row, int col) {

        return (row/3)*3+(col/3);

    }

    public boolean isValidSudoku(char[][] board) {

        Set<Integer>[] rows = new Set[9];
        Set<Integer>[] columns = new Set[9];
        Set<Integer>[] squares = new Set[9];

        for (int i = 0; i<9; i++) {
            rows[i] = new HashSet<>();
            columns[i] = new HashSet<>();
            squares[i] = new HashSet<>();        
        }

        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                if (board[r][c]=='.') {
                    continue;
                }

                int val = board[r][c]-'0';
                int squareIndex = calcSquare(r,c);

                if (rows[r].contains(val)) {
                    return false;
                }

                if (columns[c].contains(val)) {
                    return false;
                }

                if (squares[squareIndex].contains(val)) {
                    return false;
                }

                rows[r].add(val);

                columns[c].add(val);

                squares[squareIndex].add(val);
                
            }
        }

        return true;
    }
}
