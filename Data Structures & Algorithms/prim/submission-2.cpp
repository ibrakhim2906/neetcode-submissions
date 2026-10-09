class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges)
        {

            int n1 = edge[0], n2 = edge[1], w = edge[2];
            adj[n1].push_back({n2, w});
            adj[n2].push_back({n1, w});
        }

        // w n1 n2 in minHeap, lexi order
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        for (auto [n2, w] : adj[0])
        {
            minHeap.push({w, 0, n2});
        }

        vector<bool> visited(n, false);
        visited[0] = true;

        int total = 0;
        
        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            int w = top[0], n1 = top[1], n2 = top[2];
            minHeap.pop();

            if (visited[n2])
            {
                continue;
            }

            total += w;
            visited[n2] = true;

            for (auto [nn, nw] : adj[n2])
            {
                if (visited[nn])
                {
                    continue;
                }

                minHeap.push({nw, n2, nn});

            }
           
        }

        for (bool v : visited)
        {
            if (!v)
            {
                return -1;
            }
        }

        return total;
        
    }
};

