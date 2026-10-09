class Solution {
public:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {

        int time = 0;
        
        int ROWS = grid.size(), COLS = grid[0].size();

        deque<pair<int, int>> q;

        int total = 0;
        int rotted = 0;

        for (int r = 0 ; r < ROWS; r++)
        {
            for (int  c= 0 ; c<COLS ;c++)
            {
                if (grid[r][c] == 1)
                {
                    total++;
                }
                if (grid[r][c]==2)
                {
                    q.push_back({r,c});

                    rotted++;
                    total++;
                }
            }
        }

        if (total == rotted)
        {
            return 0;
        }

        while (!q.empty() && rotted < total)
        {

            int sz = q.size();

            for (int n = 0; n<sz; n++){
            pair<int, int> coord = q.front();

            q.pop_front();

            for (auto dir : directions)
            {
                int r = coord.first+dir.first;
                int c = coord.second+dir.second;

                if (r >= 0 && c>=0 && c<COLS && r<ROWS && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    rotted++;

                    q.push_back({r,c});
                }
            }
            }
            
            time++;
        }

        return (rotted == total) ? time : -1;

        
        
    }
};
