class Solution {
    private int[][] directions = {{1,0}, {-1,0}, {1,1}, {-1,1}, {0,1}, {0,-1}, {1,-1}, {-1,-1}};
    public int shortestPathBinaryMatrix(int[][] grid) {
        int ROWS = grid.length;
        int COLS = grid[0].length;

        if (grid[0][0]==1 || grid[ROWS-1][COLS-1]==1) {
            return -1;
        }

        boolean[][] visited = new boolean[ROWS][COLS];
        Deque<int[]> queue = new LinkedList<>(); 

        visited[0][0]=true;
        queue.add(new int[]{0,0});

        int length=1;
        while (!queue.isEmpty()) {
            int qSize = queue.size();
            for (int i=0; i<qSize; i++) {
                int[] pair = queue.poll();
                int r = pair[0], c = pair[1];

                if (r == ROWS-1 && c == COLS-1) {
                    return length;
                }
                
                for (int[] dir : directions) {
                    int newR = r+dir[0], newC = c+dir[1];

                    if (newR<0 || newC<0 || newR>=ROWS || newC>=COLS || grid[newR][newC]==1 || visited[newR][newC]==true) {
                        continue;
                    }

                    queue.add(new int[]{newR, newC});
                    visited[newR][newC]=true;
                }
            }
            
            length++;
        }

        return -1;
        
    }
}