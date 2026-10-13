class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<vector<int>>> adj(n);

        for (auto& flight : flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<vector<int>> best(n, vector<int>(k+2, INT_MAX));

        best[src][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap;
        minheap.push({0, src, -1});

        while (!minheap.empty())
        {
            auto top = minheap.top();
            minheap.pop();
            int cost = top[0], node = top[1], stops = top[2];

            if (node == dst) return cost;

            if (stops == k || best[node][stops+1] < cost) continue;

            for (auto a : adj[node])
            {
                int nei = a[0], w = a[1];

                int nextcost = cost+w;
                int nextstops = stops+1;
                if (best[nei][nextstops+1] > nextcost)
                {
                    best[nei][nextstops+1] = nextcost;
                    minheap.push({nextcost, nei, nextstops});
                }
            }
        }

        return -1;

        


        
    }
};
