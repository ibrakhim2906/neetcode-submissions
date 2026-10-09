class Solution {
   public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        if (ROWS == 1) return grid[0][0];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minHeap;

        minHeap.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        visited[0][0] = true;

        while (!minHeap.empty()) {
            auto [time, x, y] = minHeap.top();

            minHeap.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= ROWS || ny >= COLS) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                if (nx == ROWS - 1 && ny == COLS - 1) {
                    return max(time, grid[nx][ny]);
                }
                visited[nx][ny] = true;

                minHeap.push({max(time, grid[nx][ny]), nx, ny});
            }
        }

        return -1;
    }
};

