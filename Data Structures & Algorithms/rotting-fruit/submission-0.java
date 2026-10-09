class Solution {
    private int[][] directions = {{1,0}, {-1,0}, {0,1} ,{0,-1}};
    public int orangesRotting(int[][] grid) {
        int ROWS = grid.length;
        int COLS = grid[0].length;

        Deque<int[]> q = new LinkedList<>();

        int timer=0;
        int fresh=0;

        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++) {
                if (grid[r][c]==1) {
                    fresh++;
                }

                if (grid[r][c]==2) {
                    q.offer(new int[]{r,c});
                }
            }
        }

        while (fresh>0 && !q.isEmpty()) {
            int qSize = q.size();
            for (int i = 0; i<qSize; i++) {
                int[] pair = q.poll();
                int r = pair[0];
                int c = pair[1];
                for (int[] dir : directions) {
                    int row = r + dir[0], col = c + dir[1];

                    if (row>=0 && col>=0 && row<ROWS && col<COLS && grid[row][col]==1) {
                        grid[row][col]=2;
                        q.offer(new int[]{row, col});
                        fresh--;
                    }
                }
            }

            timer++;
        }
        return fresh==0 ? timer : -1;
    }

}
