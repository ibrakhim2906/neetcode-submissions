class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int N = points.size();

        unordered_map<int, vector<pair<int, int>>> adj;
        

        for (int i = 0 ; i < N; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1 ; j < N; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int res = 0;

        vector<bool> visited(N, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        minHeap.push({0,0});

        while (!minHeap.empty())
        {
            auto [w_curr, n_curr] = minHeap.top();
            minHeap.pop();

            if (visited[n_curr])
            {
                continue;
            }

            res += w_curr;
            visited[n_curr] = true;

            for (const auto& nei : adj[n_curr])
            {
                int n_nei = nei.first;
                int w_nei = nei.second;

                if (visited[n_nei])
                {
                    continue;
                }

                minHeap.push({w_nei, n_nei});
            }
        }

        return res;
        
        
    }
};
