class Solution {

    private int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    public int shortestPath(int[][] grid) {
        int ans = bfs(grid);

        return ans;
        
    }

    public int bfs(int[][] grid) {
        int ROWS = grid.length;
        int COLS = grid[0].length;

        if (grid[0][0]==1 || grid[ROWS-1][COLS-1]==1) {
            return -1;
        }

        
        Deque<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[ROWS][COLS];

        int length=0;
        queue.add(new int[]{0,0});
        visited[0][0]=true;

        while (!queue.isEmpty()) {
            int queueSize=queue.size();
            for (int i = 0; i<queueSize; i++) {
                int pair[] = queue.poll();
                int r = pair[0], c = pair[1];
                if (r==ROWS-1 && c==COLS-1) {
                    return length;
                }

                for (int[] dir : directions) {
                    int newR=r+dir[0], newC=c+dir[1];

                    if (newR<0 || newC<0 || newR>=ROWS || newC>=COLS ||  visited[newR][newC]==true || grid[newR][newC]==1) {
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
