class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        int res=0;


        vector<vector<pair<int, int>>> adj(n+1);

        for (auto& time : times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }

        unordered_map<int, int> resMap;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, k});

        while (!minHeap.empty())
        {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();

            if (resMap.contains(n1))
            {
                continue;
            }

            res=w1;;
            resMap[n1] = w1;

            for (auto& [n2, w2] : adj[n1] )
            {

                if (resMap.contains(n2))
                {
                    continue;
                }

                minHeap.push({w2+w1, n2});
                
            }
        }

        if (resMap.size() < n)
        {
            return -1;
        }
        return res;
        
        
    }
};
