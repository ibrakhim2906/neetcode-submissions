class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0 ; i < edges.size(); i++)
        {

            int x = edges[i][0], y = edges[i][1];
            double prob = succProb[i];
            adj[x].push_back({y,prob});
            adj[y].push_back({x,prob});
        }

        vector<double> bestProb(n, 0.0);
        bestProb[start_node] = 1.0;

        priority_queue<pair<double, int>, vector<pair<double, int>>> maxHeap;

        maxHeap.push({1.0,start_node});
        
        while (!maxHeap.empty())
        {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            if (prob < bestProb[node])
            {
                continue;
            }


            if (node == end_node)
            {
                return prob;
            }

            for (auto [nei, neiProb] : adj[node])
            {
                double newProb = prob * neiProb;
                if (newProb > bestProb[nei])
                {
                    bestProb[nei] = newProb;
                    maxHeap.push({newProb, nei});
                }

            }
        }

        if (bestProb[end_node] == 0.0)
        {
            return 0;
        }

        return bestProb[end_node];
        
    }
};