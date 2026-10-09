class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {

        vector<vector<pair<int, int>>> adj(n);


        for (auto& edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        unordered_map<int, int> shortest(n);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        minHeap.push({0, src});

        while (!minHeap.empty())
        {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();

            if (shortest.contains(n1))
            {
                continue;
            }

            shortest[n1] = w1;

            for (auto& [n2, w2] : adj[n1])
            {

                if (shortest.contains(n2))
                {
                    continue;
                }

                minHeap.push({w1+w2, n2});

            }
        }

        for (int i = 0 ; i < n ; i ++)
        {
            if (!shortest.contains(i)) shortest[i]=-1;
        }

        return shortest;
        
    }
};
