class Solution {
public:

    vector<pair<int,int>> directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int ROWS = grid.size(), COLS= grid[0].size();
        deque<pair<int,int>> q{};

        for (int r = 0; r< ROWS; r++)
        {
            for (int c = 0; c< COLS; c++)
            {
                if (grid[r][c] == 0)
                {
                    q.push_back({r,c});
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> coord = q.front();
            q.pop_front();

            for (auto pr : directions)
            {
                int r = coord.first + pr.first;
                int c = coord.second + pr.second;

                if (r >= 0 && c >= 0 && r<ROWS && c < COLS && grid[r][c] == INT_MAX)

                {
                    grid[r][c] = grid[coord.first][coord.second]+1;

                    q.push_back({r, c});
                }
            }
        }

        

        

        
        
    }
};
