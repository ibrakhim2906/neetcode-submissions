class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<vector<int>>> adj(n);
        for (auto& flight : flights)
            adj[flight[0]].push_back({flight[1], flight[2]});

        // best[city][used] = cheapest cost to be at city after exactly `used` flights
        vector<vector<int>> best(n, vector<int>(k + 2, INT_MAX));
        best[src][0] = 0;

        // heap of {cost, city, used}, cheapest first
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap;
        minheap.push({0, src, 0});

        while (!minheap.empty())
        {
            auto top = minheap.top();
            minheap.pop();
            int cost = top[0], node = top[1], used = top[2];

            if (node == dst) return cost;

            if (used == k + 1 || best[node][used] < cost) continue;

            for (auto& a : adj[node])
            {
                int nei = a[0], w = a[1];
                int nextcost = cost + w;
                int nextused = used + 1;
                if (best[nei][nextused] > nextcost)
                {
                    best[nei][nextused] = nextcost;
                    minheap.push({nextcost, nei, nextused});
                }
            }
        }
        return -1;
    }
};